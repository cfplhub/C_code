#include<graphics.h>
#include<Windows.h>
#include<conio.h>
#include<stdio.h>


#define  column 19
#define  row 19
//��������
int judgement(int x, int y);
void drawchessboard();
void XiaQi();
int caculateValue(int r, int c, int who);
int MaxOfQuan(int r, int c);
void AIReboot();
int caculateValue(int r, int c, int who);
int MaxOfQuan(int r, int c);


//ȫ�ֱ���
IMAGE black, white, background, renren, surrender, renji, mainpicture;//ͼƬȫ�ֱ���
HWND h;//֮���������ܵ�ǰ��ͼ���ھ��
int turn = 0;//�������� 0��������  1������  2������
int map[row][column] = { 0 };//�洢������Ϣ  0û������  1����  2����
int chooseType = 0;//1Ϊ���� 2Ϊ�˻�
int gif = 0;//���Ʋ˵�������ͼ

struct quanzhi
{
    int hang, lie, yuoxie, zouxie;//�洢�ĸ���������������  \ /   
};
quanzhi quan[row][column];//��¼����λ��

void AIReboot()//����������
{
    memset(quan, 0, sizeof(quan));//��������
    int i, j, tmp, max1 = 0, a1 = 0, b1 = 0;
    for (i = 0; i < row; i++)//��������
    {
        for (j = 0; j < column; j++)
        {
            if (map[j] != 0)
                continue;
            caculateValue(i, j, 1);//����з�����λ��  ����
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
            caculateValue(i, j, 2);//���㼺������λ��  ����
            tmp = MaxOfQuan(i, j);
            if (max2 < tmp)
            {
                max2 = tmp;
                a2 = i;
                b2 = j;
            }
        }
    }
    if (max2 != 0 && max2 >= max1)//����  ��������з��������������ͬʱ ���������ȼ�����
    {
        putimage(b2 * 40, a2 * 40, &white);
        map[a2][b2] = 2;
        if (judgement(b2, a2) != 2)
            turn = 1;
    }
    else//����
    {
        putimage(b1 * 40, a1 * 40, &white);
        map[a1][b1] = 2;
        if (judgement(b1, a1) != 2)
            turn = 1;

    }



}

int caculateValue(int r, int c, int who)//����Ȩֵ
{

    //������
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


    //��
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


    //��б
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


    //��б
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

void drawchessboard()//��������
{
    int i, j;
    cleardevice();//����
    putimage(0, 0, &background);//������ͼ���˵�ͼ
    putimage(780, 100, 200, 55, &renren, 298, 85);
    putimage(780, 200, 200, 55, &renji, 298, 85);
    putimage(780, 300, 200, 55, &surrender, 298, 85);

    setlinecolor(BLACK);//�����ߵ���ɫΪ��ɫ
    for (i = 1, j = 1; j < 20; i += 2, j++)//����19x19����
    {
        line(20, 20 * i, 40 * column - 20, 20 * i);
        line(20 * i, 20, 20 * i, 40 * row - 20);
    }
}
void XiaQi()
{
    MOUSEMSG m;//���
    while (1)
    {
        m = GetMouseMsg();//��ȡ�����Ϣ
        switch (m.uMsg)
        {
        case WM_LBUTTONDOWN://����������
            if (m.x >= 780 && m.x <= 980 && m.y >= 100 && m.y <= 155)//�����ʼ���ˣ���Ϸ��ʼ����������
            {
                if (turn == 0)//��ʼ��Ϸ
                {
                    turn = 1;//��������

                    chooseType = 1;
                    drawchessboard();
                    memset(map, 0, sizeof(map));
                    MessageBox(h, "��Ϸ��ʼ  ������", "��ʾ��Ϣ", MB_OK);//������ʾ��
                    outtextxy(800, 50, "��ǰģʽ��˫��ģʽ");
                    outtextxy(800, 455, "��ǰִ�ӣ�");
                    putimage(900, 440, &black);
                    break;
                }
                else
                    MessageBox(h, "����Ϸ����������", "��ʾ��Ϣ", MB_OK);//������ʾ��
            }
            else if (m.x >= 780 && m.x <= 980 && m.y >= 200 && m.y <= 255)//�˻�ģʽ  
            {
                if (turn == 0)//��ʼ��Ϸ
                {
                    turn = 1;
                    chooseType = 2;
                    drawchessboard();
                    memset(map, 0, sizeof(map));
                    MessageBox(h, "��Ϸ��ʼ  ������", "��ʾ��Ϣ", MB_OK);//������ʾ��
                    outtextxy(800, 50, "��ǰģʽ������ģʽ");
                    outtextxy(800, 455, "����ִ�ӣ�");
                    putimage(900, 440, &black);
                    break;
                }
                else
                    MessageBox(h, "����Ϸ����������", "��ʾ��Ϣ", MB_OK);//������ʾ��
            }
            else if (m.x >= 780 && m.x <= 980 && m.y >= 300 && m.y <= 355)//����  ��ǰ�ֵ�˭  ˭��
            {
                if (turn == 1)
                {
                    MessageBox(h, "�ڷ����� �׷�ʤ������", "��ʾ��Ϣ", MB_OK);//������ʾ��
                    turn = 0;
                    chooseType = 0;
                }
                else if (turn == 2)
                {
                    MessageBox(h, "�׷����� �ڷ�ʤ������", "��ʾ��Ϣ", MB_OK);//������ʾ��
                    turn = 0;
                    chooseType = 0;
                }
                else
                    MessageBox(h, "��Ϸδ��ʼ �������䣡����", "��ʾ��Ϣ", MB_OK);//������ʾ��
            }
            else if (turn == 0)
                MessageBox(h, "�뿪ʼ��Ϸ������", "��ʾ��Ϣ", MB_OK);
            if (chooseType == 1)//���˴�ս
            {
                if (turn == 1)//��������
                {
                    putimage(900, 440, &white);
                    int x = m.x, y = m.y;//�������������������̿ո�
                    int true_x = x / 40 * 40 + 20, true_y = y / 40 * 40 + 20;
                    if (true_x > 760 || true_y > 760)
                    {
                        MessageBox(h, "���ﲻ�����̣�����", "��ʾ��Ϣ", MB_OK);//������ʾ��
                    }
                    else
                    {
                        int locate_x = (true_x - 20) / 40, locate_y = (true_y - 20) / 40;//����map������±�
                        if (map[locate_y][locate_x] == 0)
                        {
                            putimage(true_x - 20, true_y - 20, &black);
                            map[locate_y][locate_x] = 1;
                            if (judgement(locate_x, locate_y) != 1)
                                turn = 2;
                        }
                        else
                            MessageBox(h, "�����Ѿ��������ˣ������£�����", "��ʾ��Ϣ", MB_OK);//������ʾ��
                    }
                }
                else if (turn == 2)//��������
                {
                    putimage(900, 440, &black);
                    int x = m.x, y = m.y;
                    int true_x = x / 40 * 40 + 20, true_y = y / 40 * 40 + 20;
                    if (true_x > 760 || true_y > 760)
                        MessageBox(h, "���ﲻ�����̣�����", "��ʾ��Ϣ", MB_OK);//������ʾ��
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
                            MessageBox(h, "�����Ѿ��������ˣ������£�����", "��ʾ��Ϣ", MB_OK);//������ʾ��
                    }
                }
            }
            else if (chooseType == 2)//�˻�ģʽ
            {
                if (turn == 0)
                    continue;
                else
                {
                    int x = m.x, y = m.y;
                    int true_x = x / 40 * 40 + 20, true_y = y / 40 * 40 + 20;
                    if (true_x > 760 || true_y > 760)
                    {
                        MessageBox(h, "���ﲻ�����̣�����", "��ʾ��Ϣ", MB_OK);//������ʾ��
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
                            MessageBox(h, "�����Ѿ��������ˣ������£�����", "��ʾ��Ϣ", MB_OK);//������ʾ��
                            continue;
                        }
                    }
                    AIReboot();//������
                }
            }
        case WM_MOUSEMOVE:
            if (m.x >= 780 && m.x <= 980 && m.y >= 100 && m.y <= 155 && gif == 0)
            {
                fillrectangle(780, 100, 980, 155);
                outtextxy(830, 110, "  ˫��ģʽ");
                gif = 1;
            }

            else if (m.x >= 780 && m.x <= 980 && m.y >= 200 && m.y <= 255 && gif == 0)
            {
                fillrectangle(780, 200, 980, 255);
                outtextxy(830, 210, "  ����ģʽ");
                gif = 2;
            }
            else if (m.x >= 780 && m.x <= 980 && m.y >= 300 && m.y <= 355 && gif == 0)
            {
                fillrectangle(780, 300, 980, 355);
                outtextxy(840, 310, "   ����");
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
int judgement(int x, int y)//�ж��Ƿ�ʤ��
{
    //��
    int r1 = x - 4, r2 = x + 4, i, j, rsum = 0;
    if (r1 < 0)  r1 = 0;
    if (r2 > 18) r2 = 18;
    if (turn == 1) //����
    {
        for (i = r1; i <= r2; i++)
        {
            if (map[y] == 1)
            {
                rsum++;
                if (rsum == 5)
                {
                    outtextxy(800, 510, "��ʤ�ߣ�");
                    putimage(900, 500, &black);
                    MessageBox(h, "��Ϸ���� �ڷ�ʤ������", "��ʾ��Ϣ", MB_OK);//������ʾ��
                    //outtextxy(750,525,"��Ϸ���� �ڷ�����5��  ʤ������");
                    turn = 0;
                    chooseType = 0;
                    return 1;//����������ӣ��ڷ�ʤ����1
                }
            }
            else
                rsum = 0;
        }
    }
    else if (turn == 2) {//����
        for (i = r1; i <= r2; i++) {
            if (map[y] == 2) {
                rsum++;
                if (rsum == 5) {
                    outtextxy(800, 510, "��ʤ�ߣ�");
                    putimage(900, 500, &white);
                    MessageBox(h, "��Ϸ���� �׷�����5��  �׷�ʤ������", "��ʾ��Ϣ", MB_OK);//������ʾ��
                    turn = 0;
                    chooseType = 0;
                    return 2;//����������ӣ��׷�ʤ����2
                }
            }
            else
                rsum = 0;
        }
    }

    //��
    int c1 = y - 4, c2 = y + 4, csum = 0;
    if (c1 < 0)
        c1 = 0;
    if (c2 > 18)
        c2 = 18;
    if (turn == 1) {//����
        for (i = c1; i <= c2; i++) {
            if (map[x] == 1) {
                csum++;
                if (csum == 5) {
                    outtextxy(800, 510, "��ʤ�ߣ�");
                    putimage(900, 500, &black);
                    MessageBox(h, "��Ϸ���� �ڷ�����5��  �ڷ�ʤ������", "��ʾ��Ϣ", MB_OK);//������ʾ��
                    turn = 0;
                    chooseType = 0;
                    return 1;//����������ӣ��ڷ�ʤ����1
                }
            }
            else
                csum = 0;
        }
    }
    else if (turn == 2) {//����
        for (i = c1; i <= c2; i++) {
            if (map[x] == 2) {
                csum++;
                if (csum == 5) {
                    outtextxy(800, 510, "��ʤ�ߣ�");
                    putimage(900, 500, &white);
                    MessageBox(h, "��Ϸ���� �׷�����5��  �׷�ʤ������", "��ʾ��Ϣ", MB_OK);//������ʾ��
                    turn = 0;
                    chooseType = 0;
                    return 2;//����������ӣ��׷�ʤ����1
                }
            }
            else
                csum = 0;
        }
    }

    //�ж�  \ ����
    int a1 = y - 4, a2 = x - 4, b1 = y + 4, b2 = x + 4, asum = 0;//a1��   a2��
    if (a1 < 0) a1 = 0;
    if (a2 < 0) a2 = 0;
    if (b1 > 18) b1 = 18;
    if (b2 > 18) b2 = 18;
    if (turn == 1) {//����
        for (i = a1, j = a2; i <= b1 && j <= b2; i++, j++) {
            if (map[j] == 1) {
                asum++;
                if (asum == 5) {
                    outtextxy(800, 510, "��ʤ�ߣ�");
                    putimage(900, 500, &black);
                    MessageBox(h, "��Ϸ���� �ڷ���б��5��  �ڷ�ʤ������", "��ʾ��Ϣ", MB_OK);//������ʾ��
                    turn = 0;
                    chooseType = 0;
                    return 1;//����������ӣ��ڷ�ʤ����1
                }
            }
            else
                asum = 0;
        }
    }
    else if (turn == 2) {//����
        for (i = a1, j = a2; i <= b1 && j <= b2; i++, j++) {
            if (map[j] == 2) {
                asum++;
                if (asum == 5) {
                    outtextxy(800, 510, "��ʤ�ߣ�");
                    putimage(900, 500, &white);
                    MessageBox(h, "��Ϸ���� �׷���б��5��  �׷�ʤ������", "��ʾ��Ϣ", MB_OK);//������ʾ��
                    turn = 0;
                    chooseType = 0;
                    return 2;//����������ӣ��׷�ʤ����2
                }
            }
            else
                asum = 0;
        }
    }


    //�ж�  / ����
    int m1 = y + 4, m2 = x - 4, n1 = y - 4, n2 = x + 4, msum = 0;//a1��   a2��
    if (m1 > 18) a1 = 18;
    if (m2 < 0) m2 = 0;
    if (n1 < 0) n1 = 0;
    if (n2 > 18) n2 = 18;
    if (turn == 1) {//����
        for (i = m1, j = m2; i >= n1 && j <= n2; i--, j++) {
            if (map[j] == 1) {
                msum++;
                if (msum == 5) {
                    outtextxy(800, 510, "��ʤ�ߣ�");
                    putimage(900, 500, &black);
                    MessageBox(h, "��Ϸ���� �ڷ���б��5��  �ڷ�ʤ������", "��ʾ��Ϣ", MB_OK);//������ʾ��
                    turn = 0;
                    chooseType = 0;
                    return 1;//����������ӣ��ڷ�ʤ����1
                }
            }
            else
                msum = 0;
        }
    }
    else if (turn == 2) {//����
        for (i = m1, j = m2; i >= n1 && j <= n2; i--, j++) {
            if (map[j] == 2) {
                msum++;
                if (msum == 5) {
                    outtextxy(800, 510, "��ʤ�ߣ�");
                    putimage(900, 500, &white);
                    MessageBox(h, "��Ϸ���� �׷���б��5��  �׷�ʤ������", "��ʾ��Ϣ", MB_OK);//������ʾ��
                    turn = 0;
                    chooseType = 0;
                    return 2;//����������ӣ��׷�ʤ����2
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

    loadimage(&renren, ("����.png"));
    loadimage(&renji, ("�˻�.png"));
    loadimage(&surrender, ("����.png"));
    loadimage(&black, "black.png");
    loadimage(&white, "white.png");
    initgraph(1030, 750);
    h = GetHWnd();//��ȡ��ͼ���ھ��
    //SetWindowLong(h , GWL_STYLE , GetWindowLong(h,GWL_STYLE)-WS_CAPTION);//ȥ��������
    //SetWindowPos(h , HWND_TOP , 0 , 0 , GetSystemMetrics(SM_CXSCREEN) , GetSystemMetrics(SM_CXSCREEN) , SWP_SHOWWINDOW);//����ȫ��
    settextcolor(BLACK);
    setbkmode(TRANSPARENT);
    setfillcolor(RGB(255, 0, 0));
    putimage(-20, 0, &mainpicture);
    //drawchessboard();
    XiaQi();
    _getch();
    closegraph();
    return 0;