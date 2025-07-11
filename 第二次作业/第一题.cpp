/*JuanjuanCaier-123456*/
#include <iostream>  
#include<cstring>
#include<vector>
using namespace std;

void Check(vector<char>& StoreChar) {
    int LoopOfDelete = 0, LoopFromFront = 0, LoopFromEnd = 0, LengthOfVector = StoreChar.size();
    while (LoopOfDelete <= (LengthOfVector - 1)) {
        vector<char> CopyStoreChar = StoreChar;//复制便于删除
        auto DeletePow = CopyStoreChar.begin() + LoopOfDelete;//获得要删除的元素的位置
        CopyStoreChar.erase(DeletePow);//删除元素
        LoopFromFront = 0;
        LoopFromEnd = LengthOfVector - 2;
        while (1) {
            if (CopyStoreChar[LoopFromFront] != CopyStoreChar[LoopFromEnd]) {
                break;
            }
            if (LoopFromFront >= LoopFromEnd) {
                cout << "True" << endl;
                return;
            }
            LoopFromFront++;
            LoopFromEnd--;
        }
        LoopOfDelete++;
    }
    if (LoopOfDelete == LengthOfVector) {
        cout << "False" << endl;
    }
}

int main() {
    char InputChar = 0;
    vector<char> StoreChar;
    cout << "请输入一个非空字符串：" << endl;
    while ((InputChar = getchar()) && (InputChar != '\n')) {//循环读入，到回车停止
        StoreChar.push_back(InputChar);
    }
    Check(StoreChar);
    return 0;
}
