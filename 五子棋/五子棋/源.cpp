#include<graphics.h>
#include<Windows.h>
#include<conio.h>
#include<stdio.h>


#define  column 19
#define  row 19
//函数声明
int judgement(int x, int y);
void drawchessboard();
void XiaQi();
int caculateValue(int r, int c, int who);
int MaxOfQuan(int r, int c);
void AIReboot();
int caculateValue(int r, int c, int who);
int MaxOfQuan(int r, int c);


//全局变量
IMAGE black, white, background, renren, surrender, renji, mainpicture;//图片全局变量
HWND h;//之后用来接受当前绘图窗口句柄
int turn = 0;//控制下棋 0都不能下  1黑棋下  2白棋下
int map[row][column] = { 0 };//存储棋盘信息  0没有棋子  1黑棋  2白棋
int chooseType = 0;//1为人人 2为人机
int gif = 0;//控制菜单处的贴图

struct quanzhi
{
    int hang, lie, yuoxie, zouxie;//存储四个方向相邻棋子数  \ /   
};
quanzhi quan[row][column];//记录最优位置

void AIReboot()//机器人下棋
{
    memset(quan, 0, sizeof(quan));//数组置零
    int i, j, tmp, max1 = 0, a1 = 0, b1 = 0;
    for (i = 0; i < row; i++)//遍历棋盘
    {
        for (j = 0; j < column; j++)
        {
            if (map[j] != 0)
                continue;
            caculateValue(i, j, 1);//计算敌方最优位置  防御
            tmp = MaxOfQuan(i, j);
            if (max1 < tmp)
            {
                max1 = tmp;
                a1 = i;
                b1 = j;
            }
        }
    }

    memset(quan, 0, sizeof(quan));
    int max2 = 0, a2 = 0, b2 = 0;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
        {
            if (map[j] != 0)
                continue;
            caculateValue(i, j, 2);//计算己方最优位置  进攻
            tmp = MaxOfQuan(i, j);
            if (max2 < tmp)
            {
                max2 = tmp;
                a2 = i;
                b2 = j;
            }
        }
    }
    if (max2 != 0 && max2 >= max1)//攻击  当己方与敌方最多相连棋子相同时 己方的优先级更大
    {
        putimage(b2 * 40, a2 * 40, &white);
        map[a2][b2] = 2;
        if (judgement(b2, a2) != 2)
            turn = 1;
    }
    else//防御
    {
        putimage(b1 * 40, a1 * 40, &white);
        map[a1][b1] = 2;
        if (judgement(b1, a1) != 2)
            turn = 1;

    }



}

int caculateValue(int r, int c, int who)//计算权值
{

    //计算行
    int sum = 0, i;
    for (i = 1; i < 5; i++)
    {
        if (c - i >= 0 && map[r][c - i] == who)
            sum++;
        if (map[r][c - i] != who)
            break;
    }
    for (i = 1; i < 5; i++)
    {
        if (c + i < 19 && map[r][c + i] == who)
            sum++;
        if (map[r][c + i] != who)
            break;
    }
    quan[r][c].hang = sum;


    //列
    sum = 0;
    for (i = 1; i < 5; i++)
    {
        if (r - i >= 0 && map[r - i][c] == who)
            sum++;
        if (map[r - i][c] != who)
            break;
    }
    for (i = 1; i < 5; i++)
    {
        if (r + i < 19 && map[r + i][c] == who)
            sum++;
        if (map[r + i][c] != who)
            break;
    }
    quan[r][c].lie = sum;


    //左斜
    sum = 0;
    for (i = 1; i < 5; i++)
    {
        if (r + i < 19 && c - i >= 0 && map[r + i][c - i] == who)
            sum++;
        if (map[r + i][c - i] != who)
            break;
    }
    for (i = 1; i < 5; i++)
    {
        if (r - i >= 0 && c + i < 19 && map[r - i][c + i] == who)
            sum++;
        if (map[r - i][c + i] != who)
            break;

    }
    quan[r][c].zouxie = sum;


    //右斜
    sum = 0;
    for (i = 1; i < 5; i++)
    {
        if (r - i >= 0 && c - i >= 0 && map[r - i][c - i] == who)
            sum++;
        if (map[r - i][c - i] != who)
            break;
    }
    for (i = 1; i < 5; i++)
    {
        if (r + i < 19 && c + i < 19 && map[r + i][c + i] == who)
            sum++;
        if (map[r + i][c + i] != who)
            break;
    }
    quan[r][c].yuoxie = sum;
    return 0;
}

int MaxOfQuan(int r, int c)
{
    int max = max(quan[r][c].hang, max(quan[r][c].lie, max(quan[r][c].yuoxie, quan[r][c].zouxie)));

    return max;

}

void drawchessboard()//绘制棋盘
{
    int i, j;
    cleardevice();//清屏
    putimage(0, 0, &background);//贴背景图、菜单图
    putimage(780, 100, 200, 55, &renren, 298, 85);
    putimage(780, 200, 200, 55, &renji, 298, 85);
    putimage(780, 300, 200, 55, &surrender, 298, 85);

    setlinecolor(BLACK);//设置线的颜色为黑色
    for (i = 1, j = 1; j < 20; i += 2, j++)//绘制19x19棋盘
    {
        line(20, 20 * i, 40 * column - 20, 20 * i);
        line(20 * i, 20, 20 * i, 40 * row - 20);
    }
}
void XiaQi()
{
    MOUSEMSG m;//鼠标
    while (1)
    {
        m = GetMouseMsg();//获取鼠标信息
        switch (m.uMsg)
        {
        case WM_LBUTTONDOWN://鼠标左键按下
            if (m.x >= 780 && m.x <= 980 && m.y >= 100 && m.y <= 155)//点击开始人人，游戏开始，黑棋先下
            {
                if (turn == 0)//开始游戏
                {
                    turn = 1;//黑棋先手

                    chooseType = 1;
                    drawchessboard();
                    memset(map, 0, sizeof(map));
                    MessageBox(h, "游戏开始  请下棋", "提示信息", MB_OK);//弹出提示框
                    outtextxy(800, 50, "当前模式：双人模式");
                    outtextxy(800, 455, "当前执子：");
                    putimage(900, 440, &black);
                    break;
                }
                else
                    MessageBox(h, "请游戏结束后重试", "提示信息", MB_OK);//弹出提示框
            }
            else if (m.x >= 780 && m.x <= 980 && m.y >= 200 && m.y <= 255)//人机模式  
            {
                if (turn == 0)//开始游戏
                {
                    turn = 1;
                    chooseType = 2;
                    drawchessboard();
                    memset(map, 0, sizeof(map));
                    MessageBox(h, "游戏开始  请下棋", "提示信息", MB_OK);//弹出提示框
                    outtextxy(800, 50, "当前模式：单人模式");
                    outtextxy(800, 455, "你所执子：");
                    putimage(900, 440, &black);
                    break;
                }
                else
                    MessageBox(h, "请游戏结束后重试", "提示信息", MB_OK);//弹出提示框
            }
            else if (m.x >= 780 && m.x <= 980 && m.y >= 300 && m.y <= 355)//认输  当前轮到谁  谁输
            {
                if (turn == 1)
                {
                    MessageBox(h, "黑方认输 白方胜！！！", "提示信息", MB_OK);//弹出提示框
                    turn = 0;
                    chooseType = 0;
                }
                else if (turn == 2)
                {
                    MessageBox(h, "白方认输 黑方胜！！！", "提示信息", MB_OK);//弹出提示框
                    turn = 0;
                    chooseType = 0;
                }
                else
                    MessageBox(h, "游戏未开始 不能认输！！！", "提示信息", MB_OK);//弹出提示框
            }
            else if (turn == 0)
                MessageBox(h, "请开始游戏！！！", "提示信息", MB_OK);
            if (chooseType == 1)//人人大战
            {
                if (turn == 1)//黑棋下子
                {
                    putimage(900, 440, &white);
                    int x = m.x, y = m.y;//计算鼠标点击处最近的棋盘空格
                    int true_x = x / 40 * 40 + 20, true_y = y / 40 * 40 + 20;
                    if (true_x > 760 || true_y > 760)
                    {
                        MessageBox(h, "这里不是棋盘！！！", "提示信息", MB_OK);//弹出提示框
                    }
                    else
                    {
                        int locate_x = (true_x - 20) / 40, locate_y = (true_y - 20) / 40;//计算map数组的下标
                        if (map[locate_y][locate_x] == 0)
                        {
                            putimage(true_x - 20, true_y - 20, &black);
                            map[locate_y][locate_x] = 1;
                            if (judgement(locate_x, locate_y) != 1)
                                turn = 2;
                        }
                        else
                            MessageBox(h, "这里已经有棋子了，不能下！！！", "提示信息", MB_OK);//弹出提示框
                    }
                }
                else if (turn == 2)//白棋下子
                {
                    putimage(900, 440, &black);
                    int x = m.x, y = m.y;
                    int true_x = x / 40 * 40 + 20, true_y = y / 40 * 40 + 20;
                    if (true_x > 760 || true_y > 760)
                        MessageBox(h, "这里不是棋盘！！！", "提示信息", MB_OK);//弹出提示框
                    else
                    {

                        int locate_x = (true_x - 20) / 40, locate_y = (true_y - 20) / 40;
                        if (map[locate_y][locate_x] == 0)
                        {
                            putimage(true_x - 20, true_y - 20, &white);
                            map[locate_y][locate_x] = 2;
                            if (judgement(locate_x, locate_y) != 2)
                                turn = 1;
                        }
                        else
                            MessageBox(h, "这里已经有棋子了，不能下！！！", "提示信息", MB_OK);//弹出提示框
                    }
                }
            }
            else if (chooseType == 2)//人机模式
            {
                if (turn == 0)
                    continue;
                else
                {
                    int x = m.x, y = m.y;
                    int true_x = x / 40 * 40 + 20, true_y = y / 40 * 40 + 20;
                    if (true_x > 760 || true_y > 760)
                    {
                        MessageBox(h, "这里不是棋盘！！！", "提示信息", MB_OK);//弹出提示框
                        continue;
                    }
                    else
                    {
                        int locate_x = (true_x - 20) / 40, locate_y = (true_y - 20) / 40;
                        if (map[locate_y][locate_x] == 0)
                        {
                            putimage(true_x - 20, true_y - 20, &black);
                            map[locate_y][locate_x] = 1;
                            if (judgement(locate_x, locate_y) != 1)
                                turn = 2;
                            else
                                continue;
                        }
                        else
                        {
                            MessageBox(h, "这里已经有棋子了，不能下！！！", "提示信息", MB_OK);//弹出提示框
                            continue;
                        }
                    }
                    AIReboot();//机器人
                }
            }
        case WM_MOUSEMOVE:
            if (m.x >= 780 && m.x <= 980 && m.y >= 100 && m.y <= 155 && gif == 0)
            {
                fillrectangle(780, 100, 980, 155);
                outtextxy(830, 110, "  双人模式");
                gif = 1;
            }

            else if (m.x >= 780 && m.x <= 980 && m.y >= 200 && m.y <= 255 && gif == 0)
            {
                fillrectangle(780, 200, 980, 255);
                outtextxy(830, 210, "  单人模式");
                gif = 2;
            }
            else if (m.x >= 780 && m.x <= 980 && m.y >= 300 && m.y <= 355 && gif == 0)
            {
                fillrectangle(780, 300, 980, 355);
                outtextxy(840, 310, "   认输");
                gif = 3;
            }
            else if ((m.x < 780 || m.x > 980) || ((m.x >= 780 && m.x <= 980) && ((m.y < 100) || (m.y > 155 && m.y < 200) || (m.y > 255 && m.y < 300) || m.y > 355)) && gif != 0)
            {
                putimage(780, 100, 200, 55, &renren, 298, 85);
                putimage(780, 200, 200, 55, &renji, 298, 85);
                putimage(780, 300, 200, 55, &surrender, 298, 85);
                gif = 0;
            }
        }
    }
}
int judgement(int x, int y)//判断是否胜利
{
    //行
    int r1 = x - 4, r2 = x + 4, i, j, rsum = 0;
    if (r1 < 0)  r1 = 0;
    if (r2 > 18) r2 = 18;
    if (turn == 1) //黑棋
    {
        for (i = r1; i <= r2; i++)
        {
            if (map[y] == 1)
            {
                rsum++;
                if (rsum == 5)
                {
                    outtextxy(800, 510, "获胜者：");
                    putimage(900, 500, &black);
                    MessageBox(h, "游戏结束 黑方胜！！！", "提示信息", MB_OK);//弹出提示框
                    //outtextxy(750,525,"游戏结束 黑方行满5子  胜！！！");
                    turn = 0;
                    chooseType = 0;
                    return 1;//连续五个黑子，黑方胜返回1
                }
            }
            else
                rsum = 0;
        }
    }
    else if (turn == 2) {//白棋
        for (i = r1; i <= r2; i++) {
            if (map[y] == 2) {
                rsum++;
                if (rsum == 5) {
                    outtextxy(800, 510, "获胜者：");
                    putimage(900, 500, &white);
                    MessageBox(h, "游戏结束 白方行满5子  白方胜！！！", "提示信息", MB_OK);//弹出提示框
                    turn = 0;
                    chooseType = 0;
                    return 2;//连续五个白子，白方胜返回2
                }
            }
            else
                rsum = 0;
        }
    }

    //列
    int c1 = y - 4, c2 = y + 4, csum = 0;
    if (c1 < 0)
        c1 = 0;
    if (c2 > 18)
        c2 = 18;
    if (turn == 1) {//黑棋
        for (i = c1; i <= c2; i++) {
            if (map[x] == 1) {
                csum++;
                if (csum == 5) {
                    outtextxy(800, 510, "获胜者：");
                    putimage(900, 500, &black);
                    MessageBox(h, "游戏结束 黑方列满5子  黑方胜！！！", "提示信息", MB_OK);//弹出提示框
                    turn = 0;
                    chooseType = 0;
                    return 1;//连续五个黑子，黑方胜返回1
                }
            }
            else
                csum = 0;
        }
    }
    else if (turn == 2) {//白棋
        for (i = c1; i <= c2; i++) {
            if (map[x] == 2) {
                csum++;
                if (csum == 5) {
                    outtextxy(800, 510, "获胜者：");
                    putimage(900, 500, &white);
                    MessageBox(h, "游戏结束 白方列满5子  白方胜！！！", "提示信息", MB_OK);//弹出提示框
                    turn = 0;
                    chooseType = 0;
                    return 2;//连续五个白子，白方胜返回1
                }
            }
            else
                csum = 0;
        }
    }

    //判断  \ 方向
    int a1 = y - 4, a2 = x - 4, b1 = y + 4, b2 = x + 4, asum = 0;//a1行   a2列
    if (a1 < 0) a1 = 0;
    if (a2 < 0) a2 = 0;
    if (b1 > 18) b1 = 18;
    if (b2 > 18) b2 = 18;
    if (turn == 1) {//黑棋
        for (i = a1, j = a2; i <= b1 && j <= b2; i++, j++) {
            if (map[j] == 1) {
                asum++;
                if (asum == 5) {
                    outtextxy(800, 510, "获胜者：");
                    putimage(900, 500, &black);
                    MessageBox(h, "游戏结束 黑方右斜满5子  黑方胜！！！", "提示信息", MB_OK);//弹出提示框
                    turn = 0;
                    chooseType = 0;
                    return 1;//连续五个黑子，黑方胜返回1
                }
            }
            else
                asum = 0;
        }
    }
    else if (turn == 2) {//白棋
        for (i = a1, j = a2; i <= b1 && j <= b2; i++, j++) {
            if (map[j] == 2) {
                asum++;
                if (asum == 5) {
                    outtextxy(800, 510, "获胜者：");
                    putimage(900, 500, &white);
                    MessageBox(h, "游戏结束 白方右斜满5子  白方胜！！！", "提示信息", MB_OK);//弹出提示框
                    turn = 0;
                    chooseType = 0;
                    return 2;//连续五个白子，白方胜返回2
                }
            }
            else
                asum = 0;
        }
    }


    //判断  / 方向
    int m1 = y + 4, m2 = x - 4, n1 = y - 4, n2 = x + 4, msum = 0;//a1行   a2列
    if (m1 > 18) a1 = 18;
    if (m2 < 0) m2 = 0;
    if (n1 < 0) n1 = 0;
    if (n2 > 18) n2 = 18;
    if (turn == 1) {//黑棋
        for (i = m1, j = m2; i >= n1 && j <= n2; i--, j++) {
            if (map[j] == 1) {
                msum++;
                if (msum == 5) {
                    outtextxy(800, 510, "获胜者：");
                    putimage(900, 500, &black);
                    MessageBox(h, "游戏结束 黑方左斜满5子  黑方胜！！！", "提示信息", MB_OK);//弹出提示框
                    turn = 0;
                    chooseType = 0;
                    return 1;//连续五个黑子，黑方胜返回1
                }
            }
            else
                msum = 0;
        }
    }
    else if (turn == 2) {//白棋
        for (i = m1, j = m2; i >= n1 && j <= n2; i--, j++) {
            if (map[j] == 2) {
                msum++;
                if (msum == 5) {
                    outtextxy(800, 510, "获胜者：");
                    putimage(900, 500, &white);
                    MessageBox(h, "游戏结束 白方左斜满5子  白方胜！！！", "提示信息", MB_OK);//弹出提示框
                    turn = 0;
                    chooseType = 0;
                    return 2;//连续五个白子，白方胜返回2
                }
            }
            else
                msum = 0;
        }
    }
    return 0;
}
int main()
{
    loadimage(&mainpicture, ("2.jpg"));
    loadimage(&background, ("1.jpg"));

    loadimage(&renren, ("人人.png"));
    loadimage(&renji, ("人机.png"));
    loadimage(&surrender, ("认输.png"));
    loadimage(&black, "black.png");
    loadimage(&white, "white.png");
    initgraph(1030, 750);
    h = GetHWnd();//获取绘图窗口句柄
    //SetWindowLong(h , GWL_STYLE , GetWindowLong(h,GWL_STYLE)-WS_CAPTION);//去掉标题栏
    //SetWindowPos(h , HWND_TOP , 0 , 0 , GetSystemMetrics(SM_CXSCREEN) , GetSystemMetrics(SM_CXSCREEN) , SWP_SHOWWINDOW);//窗口全屏
    settextcolor(BLACK);
    setbkmode(TRANSPARENT);
    setfillcolor(RGB(255, 0, 0));
    putimage(-20, 0, &mainpicture);
    //drawchessboard();
    XiaQi();
    _getch();
    closegraph();
    return 0;