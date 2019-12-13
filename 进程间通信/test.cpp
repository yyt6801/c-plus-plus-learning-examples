/************************************************************************/
/*                        内存映射一                                    */
/*程序演示了如何把一个已存在的文件映射到内存中，并倒转文件内容          */
/*转载请注明文章来自:http://blog.csdn.net/windows_nt                    */
//************************************************************************/

#include <Windows.h>
#include <tchar.h>
#include <string.h> // For _strrev
#include <iostream>
#include <CommDlg.h>

typedef TCHAR *PTSTR;
#define FILENAME TEXT("FILEREV.DAT")

BOOL FileReverse(PTSTR pszPathname, PBOOL pfIsTextUnicode)
{
    *pfIsTextUnicode = FALSE; // Assume text is Unicode

    // Open the file for reading and writing.
    HANDLE hFile = CreateFile(pszPathname, GENERIC_WRITE | GENERIC_READ, 0,
                              NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

    if (hFile == INVALID_HANDLE_VALUE)
    {
        printf("File could not be opened.");
        return (FALSE);
    }

    // Get the size of the file (I assume the whole file can be mapped).
    DWORD dwFileSize = GetFileSize(hFile, NULL);

    // Create the file-mapping object. The file-mapping object is 1 character
    // bigger than the file size so that a zero character can be placed at the
    // end of the file to terminate the string (file). Because I don't yet know
    // if the file contains ANSI or Unicode characters, I assume worst case
    // and add the size of a WCHAR instead of CHAR.
    HANDLE hFileMap = CreateFileMapping(hFile, NULL, PAGE_READWRITE,
                                        0, dwFileSize + sizeof(WCHAR), NULL);

    if (hFileMap == NULL)
    {
        printf("File map could not be opened.");
        CloseHandle(hFile);
        return (FALSE);
    }

    // Get the address where the first byte of the file is mapped into memory.
    PVOID pvFile = MapViewOfFile(hFileMap, FILE_MAP_WRITE, 0, 0, 0);

    if (pvFile == NULL)
    {
        printf("Could not map view of file.");
        CloseHandle(hFileMap);
        CloseHandle(hFile);
        return (FALSE);
    }

    // Does the buffer contain ANSI or Unicode?
    int iUnicodeTestFlags = -1; // Try all tests
    *pfIsTextUnicode = IsTextUnicode(pvFile, dwFileSize, &iUnicodeTestFlags);

    if (!*pfIsTextUnicode)
    {
        // For all the file manipulations below, we explicitly use ANSI
        // functions because we are processing an ANSI file.

        // Put a zero character at the very end of the file.
        PSTR pchANSI = (PSTR)pvFile;
        pchANSI[dwFileSize / sizeof(CHAR)] = 0;

        // Reverse the contents of the file.
        _strrev(pchANSI);

        // Convert all "\n\r" combinations back to "\r\n" to
        // preserve the normal end-of-line sequence.
        pchANSI = strchr(pchANSI, '\n'); // Find first '\n'.

        while (pchANSI != NULL)
        {
            // We have found an occurrence....
            *pchANSI++ = '\r';               // Change '\n' to '\r'.
            *pchANSI++ = '\n';               // Change '\r' to '\n'.
            pchANSI = strchr(pchANSI, '\n'); // Find the next occurrence.
        }
    }
    else
    {
        // For all the file manipulations below, we explicitly use Unicode
        // functions because we are processing a Unicode file.

        // Put a zero character at the very end of the file.
        PWSTR pchUnicode = (PWSTR)pvFile;
        pchUnicode[dwFileSize / sizeof(WCHAR)] = 0;

        if ((iUnicodeTestFlags & IS_TEXT_UNICODE_SIGNATURE) != 0)
        {
            // If the first character is the Unicode BOM (byte-order-mark),
            // 0xFEFF, keep this character at the beginning of the file.
            pchUnicode++;
        }

        // Reverse the contents of the file.
        _wcsrev(pchUnicode);

        // Convert all "\n\r" combinations back to "\r\n" to
        // preserve the normal end-of-line sequence.
        pchUnicode = wcschr(pchUnicode, L'\n'); // Find first '\n'.

        while (pchUnicode != NULL)
        {
            // We have found an occurrence....
            *pchUnicode++ = L'\r';                  // Change '\n' to '\r'.
            *pchUnicode++ = L'\n';                  // Change '\r' to '\n'.
            pchUnicode = wcschr(pchUnicode, L'\n'); // Find the next occurrence.
        }
    }

    // Clean up everything before exiting.
    UnmapViewOfFile(pvFile);
    CloseHandle(hFileMap);

    // Remove trailing zero character added earlier.
    SetFilePointer(hFile, dwFileSize, NULL, FILE_BEGIN);
    SetEndOfFile(hFile);
    CloseHandle(hFile);

    return (TRUE);
}

void main()
{
    //当前目录下，必须是数字或字母且为回车结束，不然，转换出来是乱码
    PTCHAR szPathname = _T("123.txt");

    // Make copy of input file so that we don't destroy it
    if (!CopyFile(szPathname, FILENAME, FALSE))
    {
        printf("New file could not be created.");
        return;
    }

    BOOL fIsTextUnicode;
    if (FileReverse(FILENAME, &fIsTextUnicode))
    {
        // Spawn Notepad to see the fruits of our labors.
        STARTUPINFO si = {sizeof(si)};
        PROCESS_INFORMATION pi;
        TCHAR sz[] = TEXT("Notepad ") FILENAME;
        if (CreateProcess(NULL, sz,
                          NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
        {
            CloseHandle(pi.hThread);
            CloseHandle(pi.hProcess);
        }
    }
    DeleteFile(FILENAME);

    return;
}