#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    // visualize `myGraphJson`!
    string myGraphJson = "{\"kind\":{\"graph\":true},"
        "\"nodes\":[{\"id\":\"1\"},{\"id\":\"2\"}],"
        "\"edges\":[{\"from\":\"1\",\"to\":\"2\"}]}";
    cout << myGraphJson <<endl;

    
    string aaa;
    aaa = "H123456711890";
    if (aaa[8]!='0')
    {
        printf("%c\n",aaa[8]);
    }
    
    printf("end%s",aaa);
}