////仅能生成文件夹，但无法判断 
//#include <time.h>
// #include <stdio.h>
// #include <iostream>
// int main()
// {
//     time_t now=time(NULL); 
//     struct tm *ptr; ptr = localtime(&now); 
//     char wenjian[60]; 
//     strftime(wenjian,60,"E:\\%Y-%m-%d_%H-%M-%S\\",ptr);//将获得的时间路径存入wenjian 
//     char cmdchar[200]; 
//     sprintf(cmdchar,"md %s",wenjian);//将创建文件的命令存入cmdchar中 
//     system(cmdchar);//创建文件夹
// }


//以下仅适用于WINDOWS环境
#include <iostream> 
#include <experimental\filesystem> 

using namespace std; 

int main() { 
    int sizeofdate = strlen(__DATE__); 
    char* dirname = new char[4 + sizeofdate]; 
    memcpy(dirname, "E:/", 3); 
    memcpy(dirname + 4, __DATE__, sizeofdate); 

    cout << "creating directory" << endl; 
    if (!experimental::filesystem::exists(dirname)) { 
        experimental::filesystem::create_directory(dirname); 
    } 
    else { 
        cout << "directory already exists!" << endl; 
    } 

    delete[] dirname; 
    int thing; 
    cin >> thing; 

    return 0; 
} 