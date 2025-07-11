/*JuanjuanCaier-123456*/
#include <iostream>
#include <string>
#include<ctime>
#include<vector>

using namespace std;
//玩家信息
class UserInfo {
public:
    string Name;//姓名
    size_t LoginTimes;//登录时间
    int PlayedMatches;//比赛场次
    int WonMatches;//获胜场次
    double WonRate;//获胜率
    int Rank;//等级，1为beginner，2为professional，3为expert
    int Session;//登录的序列码，以此分辨多会话
    // 构造函数
    UserInfo() {
        Name = "\0";
        LoginTimes = 0;
        PlayedMatches = 0;
        WonMatches = 0;
        WonRate = 0;
        Rank = 0;
        Session = 0;
    }
    //输出该用户信息
    void OutPut() {
        cout << "姓名：" << Name << endl;
        cout << "登录时间：" << LoginTimes << endl;
        cout << "比赛场次：" << PlayedMatches << endl;
        cout << "获胜场次：" << WonMatches << endl;
        cout << "获胜率：" << WonRate << "%" << endl;
        cout << "等级：";
        if (Rank == 1) {
            cout << "beginner";
        }
        else if (Rank == 2) {
            cout << "professional";
        }
        else if (Rank == 3) {
            cout << "expert";
        }
        cout << endl;
        cout << "会话id：" << Session << endl;
    }
};
//国际象棋类
class User_Prof
{
public:
    vector<UserInfo>Sessions;

    //登录，从服务器获得该玩家信息，提供了默认名字和等级
    void Login(int P, int W, int R = 1, string N = "guest") {
        UserInfo Info;
        Info.Name = N;
        Info.LoginTimes = time(0);
        Info.PlayedMatches = P;
        Info.WonMatches = W;
        if (Info.PlayedMatches != 0) {
            Info.WonRate = Info.WonMatches / (Info.PlayedMatches*1.0) * 100;
        }
        else {
            Info.WonRate = 0;
        }
        Info.Rank = R;
        Info.Session = Sessions.size();
        Sessions.push_back(Info);
    }
    //注销，从服务器获得要注销的会话id
    void Logout(int S) {
        for (int i = 0; i < Sessions.size(); i++) {
            if (Sessions[i].Session == S) {
                auto it = Sessions.begin() + i;
                Sessions.erase(it);
                Sessions.shrink_to_fit();
                return;
            }
        }
        cout << "未找到目标会话。" << endl;
    }
    //测试两个UserInfo对象是否等价/不等价
    bool IsEqual(UserInfo& S1, UserInfo& S2) {
        if (S1.Session == S2.Session) {
            return 1;
        }
        else {
            return 0;
        }
    }
    //输出信息供对比
    void OutPut() {
        int Number = Sessions.size();
        cout << "目前共" << Number << "个会话：" << endl;
        for (int i = 0; i < Number; i++) {
            cout << ">>>第" << i + 1 << "个会话信息：" << endl;
            Sessions[i].OutPut();
        }
    }
};
//测试
int main() {
    User_Prof ChessGame;
    ChessGame.Login(100, 50, 1);//player1登录
    ChessGame.Login(100, 70, 2);//player2登录
    ChessGame.Login(200, 170, 3, "Battle");//player3登录
    ChessGame.OutPut();
    UserInfo player1 = ChessGame.Sessions[0];
    UserInfo player2 = ChessGame.Sessions[1];
    UserInfo player3 = ChessGame.Sessions[2];
    //测试等效性
    cout << "player1和player1的姓名一致，它们";
    if (ChessGame.IsEqual(player1,player1) == 1) {
        cout << "是";
    }
    else {
        cout << "不是";
    }
    cout << "同一个会话。" << endl;
    //测试不等效性
    cout << "player1和player2的姓名一致，它们";
    if (ChessGame.IsEqual(player1, player2) == 1) {
        cout << "是";
    }
    else {
        cout << "不是";
    }
    cout << "同一个会话。" << endl;
    //测试不等效性
    cout << "player1和player3，它们";
    if (ChessGame.IsEqual(player1, player3) == 1) {
        cout << "是";
    }
    else {
        cout << "不是";
    }
    cout << "同一个会话。" << endl;
    return 0;
}