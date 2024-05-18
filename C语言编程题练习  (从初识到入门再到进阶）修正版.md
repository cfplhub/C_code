# C语言编程题练习  :notebook_with_decorative_cover:(从初识到入门再到进阶）

## 小飞机 :flight_arrival:



![<img src="C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20240516161730324.png" alt="image-20240516161730324" style="zoom:50%;" />](https://img-blog.csdnimg.cn/direct/b44fe619c7204113951e1fe0a819f537.png)




````c
#include<stdio.h>

int main()
{
    printf("      **       \n");
    printf("      **       \n");
    printf("***************\n");
    printf("***************\n");
    printf("     *  *      \n");
    printf("     *  *      \n");
    
    
    return 0;
}
````

---

## 输入学生信息 :man_student:



![<img src="C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20240516162508152.png" alt="image-20240516162508152" style="zoom:50%;" />](https://img-blog.csdnimg.cn/direct/31fc58bb9115432ea802f1daedc9a761.png)


````c
#include<stdio.h>

int main()
{
    printf("Name    Age    Gender\n");
    printf("---------------------\n");
    printf("Jack     18      Man \n");
    
    
    
    return 0;
}
````

---

## 计算表达式的值



![<img src="C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20240516163654737.png" alt="image-20240516163654737" style="zoom:50%;" />](https://img-blog.csdnimg.cn/direct/8d79a430a5974077a94c73d36466af53.png)


````c
#include<stdio.h>

int main()
{
    int a = 40;
    int c = 212;
    int x;
    
    x = (-8+22) * a - 10 + c/2;
    
    printf("%d\n",x);
    
    return 0;
}
````

---

## 计算y的值



![<img src="C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20240516164113978.png" alt="image-20240516164113978" style="zoom:50%;" />](https://img-blog.csdnimg.cn/direct/10acc3bd08d1452c96fcc42be4aa47a6.png)


````c
#incldue<stdio.h>

int y(int x)
{
    int y = 0;
    
    if(x<0)
        y = 1;
    
    if else(x==0)
        y = 0;
    
    else
        y = -1;
    return y;
}


int main()
{
    
    int x;
    scanf("%d",&x);
    
    int ret = y(x);
    
    printf("%d",ret);
    
    
    retturn 0;
}
````



---

## 利用函数递归（按顺序打印数字每一位）

![<img src="C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20240516170133839.png" alt="image-20240516170133839" style="zoom:45%;" />](https://img-blog.csdnimg.cn/direct/16c1049c72824b63a98d66644aed30df.png)


**什么是递归**

> 程序调用自身的编程技巧称为递归（ recursion )。递归做为一种算法在程序设计语言中广泛应用。一个过程或函数在其定义或说明中有直接或间接调用自身的一种方法，它通常把一个大型复杂的问题层层转化为一个与原问题相似的规模较小的问题来求解，递归策略只需少量的程序就可描述出解题过程所需要的多次重复计算，大大地减少了程序的代码量。
>
> 递归的主要思考方式在于：把大事化小
>
> > **递归的两个必要条件**
> >
> > + 存在限制条件，当满足这个限制条件的时候，递归便不再继续
> > + 每次递归调用之后越来越接近这个条件





````c
#include<stdio.h>

//int main()
//{
//	unsigned int num;
//	scanf("%d", &num);//1234
//
//	while (num)
//	{
//		printf("%d ", num % 10);
//
//		num / 10;
//	}
//
//	//打印结果为： 4 3 2 1
//
//	return 0;
//}


void print(unsigned int x)
{
    if(x>9)
    {
      print(x/10);
    }
    printf("%d ",x%10);
}

int main()
{
   unsigned int x = 0;
    
    scanf("%u",&x);
    
    print(x);
    
    
    return 0;
}
````

---

## 从大到小输出数字

![<img src="C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20240516172815139.png" alt="image-20240516172815139" style="zoom:50%;" />](https://img-blog.csdnimg.cn/direct/f9430619d4e64d169350a5fc957c7ce2.png)



````c
#include<stdio.h>

int main()
{
    int a,b,c,tmp =0;
    
    //输入
    scanf("%d %d %d",&a,&b,&c);
    
    if(a<b)
    {
        tmp = a;
        a = b;
        b = tmp;
    }
    
    if(b<c)
    {
        tmp = c;
        c = b;
        b =tmp;
    }
    
    if(a<c)
    {
        tmp = a;
        a = c;
        c = tmp;
    }
    //输出
    printf("%d %d %d",a,b,c);
    
    return 0;
}
````

---

## 打印3的倍数



![<img src="C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20240516173413009.png" alt="image-20240516173413009" style="zoom:50%;" />](https://img-blog.csdnimg.cn/direct/3a69844db3c04a299bc4bd8acc9cfda0.png)


````c
#include<stdio.h>

int main()
{
    int i = 0;
    
    for(i = 1; i <= 100; i++)
    {
        if(i%3 == 0)
        {
            printf("%d ",i);
        }
    }
    
    for(i =3; i <= 100; i += 3)
    {
        printf("%d ",i);
    }
    
    return 0;
}
````

---

## 最大公约数

![<img src="C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20240516192827270.png" alt="image-20240516192827270" style="zoom:50%;" />](https://img-blog.csdnimg.cn/direct/c561b7861d444affbca0e0501a60e339.png)


````c
#include<stdio.h>

int main()
{
    int x = 0;
    int y = 0;
    int m = 0;
    
    scanf("%d %d",%x,&y);
    
    m = (a < b) ? a : b; 
    while(1)
    {
        if(a % m == 0 && b % m == 0)
        {
            break;
        }
        m--;
    }
    
    printf("%d",m);
    
    int c =0;
    
    //辗转相除法
    while(c = a % b)
    {
       // int c = a % b;
        a = b;
        b = c;
    }
    
    //最大公倍数 (a * b) / 最大公约数
    
    printf("%d",b);
    
    return 0;
}
````

---



## 打印闰年

![<img src="C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20240516194402748.png" alt="image-20240516194402748" style="zoom:50%;" />](https://img-blog.csdnimg.cn/direct/2a6eafae62b4448bb4da000fb00c685b.png)


````c
#include<stdio.h>

int main()
{
    int i = 0;
    
    for(i = 1000; i <= 2000; i++)
    {
        if(i % 4 == 0 && i % 100 != 0 || i % 400 ==0)
        {
            printf("%d\n",i);
        }
    }
    
    
    return 0;
}
````



---

## 打印素数

> **素数只能被1和它本身整除，例如判断13(i)是不是素数，就是产生2到12(2到i-1)的数字**

![<img src="C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20240516195021301.png" alt="image-20240516195021301" style="zoom:50%;" />](https://img-blog.csdnimg.cn/direct/48f7adbd63964b388a798163f2287de1.png)


````c
#include<stdio.h>

int main()
{
    //打印100-200之间的素数
	int i=0;
	int count=0;//count代表素数的个数
	for(i=100;i<=200;i++)
	{
		//判断i是否为素数
		int j=0;
		for(j=2;j<i;j++)
		{
			if(i%j==0)
			{
				break;
			}
		}//break会跳到这里
		if(j==i)
		{
			count++;
			printf("%d ",i);
		}

    }
    
    printf("\ncount=%d \n",count);
    
    return 0;
}
````

````c
#include <stdio.h>
#include <math.h>
int main(){
	
	int  i=0;
	int count=0;//count代表素数的个数
	for(i=100;i<=200;i++)
	{
		//判断i是否为素数
		int j=0;
		for(j=2;j<=sqrt(i*1.0);j++)//sqrt()开平方的数学库函数
		{
			if(i%j==0)
			{
				break;
			}
		}//break会跳到这里
		if(j>sqrt(i*1.0))
		{
			count++;
			printf("%d ",i);
		}
		
	}
	printf("\ncount=%d \n",count);
	return 0;
}
````

---

## 九九乘法表 :heavy_multiplication_x:

````c
#include<stdio.h>

int main()
{
    int i ,j = 0;
    
    for(i = 1; i < 9; i++)
    {
        for(j = 1 ; j < i; j++)
        {
            printf("%d * %d = %2d",j,i,j*i);
        }
        printf("\n");
    }
    
    
    return 0;
}
````

---

## 二分查找

````c
#include<stdio.h>

int BinarySearch(int arr[10], int len, int k)
{
    int left = 0;
    int right = len - 1;
    
    while(left < right)
    {
        int mid = (left + right) / 2; 
        if(arr[mid] > k)
        {
            right = mid - 1 ;
        }
        
        else if(arr[mid] < k)
        {
            left = mid + 1;
        }
        else
            return mid;
    }
    
    return -1;
}

//递归
int BinarySearch_(int arr[10], int left , int right , int k)
{
    
    
    if(left > right)
    {
        return -1;
    }
    else
    {
        if(arr[mid] > k)
        {
            return BinarySearch_(arr, left , mid - 1 , k);
        }
        if(arr[mid] < k)
        {
            return BinarySearch_(arr, mid + 1 , right , k)
        }
        else
            return mid;
    }
}

int main()
{
    int i = 0;
    int k = 0;
    int arr[10] = { 0 };
    
    //输入
    for(i = 0 ; i < 10 ; i++)
    {
        scanf("%d", arr[i]);
    }right
    
    int left = 0;
    
    int right = sizeof(arr) - 1;
    
    //要查找的值
    scanf("%d",&k)
    
    int ret = BinarySearch_(arr, left , right , k);
    
    if (ret != -1) {
		printf("%d查找成功\n",arr[mid]);
	}
	else {
		printf("查找失败\n");

    
    return 0;
}
````

---

## 小乐乐走台阶

![<img src="C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20240516203901297.png" alt="image-20240516203901297" style="zoom:40%;" />](https://img-blog.csdnimg.cn/direct/67530dbba6ff4933b17d82704667a09e.png)


````c
##include <stdio.h>
int Fib(int n)
{
    if (n <= 2)
    {
        return n;
    }
    else
    {
        return Fib(n - 1) + Fib(n - 2);
    }
}
 
int main()
{
    int n = 0;
    scanf("%d", &n);
    int ret = Fib(n);
    printf("%d\n", ret);
    return 0;
}

````



---

## 斐波那契数

![<img src="C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20240516210107488.png" alt="image-20240516210107488" style="zoom:33%;" />](https://img-blog.csdnimg.cn/direct/23237cb3086b4b8e870b964d8f92f79a.png)


> 斐波那契数列（Fibonacci sequence），又称“黄金分割”数列，比如这样一个数列：1，1，2，3，5，8，13，21，34，55，89... ...数列从第3项开始，每一项都等于前两项之和。在C语言中，我们可以用多种方式来实现斐波那契数列。本文针对以下三种方式来体现每种方法的效率：1.递归，2.非递归  3.数组。

1. 递归。该递归属于多分支递归，会造成栈溢出

````c
//递归
	#include<stdio.h>
 
	int Fib(int n)
	{
		if(n==1||n==2)//数列前两项
		{
		return 1;
		 }
		else//从第三项开始
		{
		return Fib(n - 1) + Fib(n - 2);
		}
		return 0;
	}
	int main()
	{
		int n = 0;
		scanf("%d", &n);//输入一个数
		int ret = Fib(n);//计算斐波那契数列
		printf("%d\n", ret);//打印结果
		return 0;
	}
````

2. [非递归](https://so.csdn.net/so/search?q=非递归&spm=1001.2101.3001.7020)。非递归较递归效率更高，避免了重复计算的时间和空间。

````c
//非递归
int main() 
{
	int n = 0;
	printf("请输入一个整数：");
	scanf("%d", &n);
	if (n == 1||n==2) {
		return 1;
	}else {
		int f1 = 1;
		int f2 = 1;
		int f3 = -1;
		for (int i = 3; i <= n; i++) {
			f3 = f1 + f2;
			f1 = f2;
			f2 = f3;
		}
		printf("该整数的Fib数列为%d", f3);
	}
 
	return 0;
}
````

3. 数组

````c
	//数组法	
	#include<stdio.h>
 
	int Fib(int n)
	{
		int i;
		int arr[100] = {0,1,1};
		for (i = 2; i <= n; i++)//从第一项开始
		{
			arr[i] = arr[i - 1] + arr[i - 2];    
		}
		return arr[n];
	}
	int main()
	{
		int n;
		scanf("%d", &n);
		printf("%d", Fib(n));
		return 0;
	}
````

---



## 字母大小写转换
**描述**

> KiKi想完成字母大小写转换，有一个字符，判断它是否为大 写字母，如果是，将它转换成小写字母；反之则转换为大写字母。

**输入描述：**

> 多组输入，每一行输入一个字母。

**输出描述:**

> 针对每组输入，输出单独占 一行，输出字母的对应形式。

示例1
```
输入：
a
A
Z
输出：
A
a
z
```

````c
#include<stdio.h>
int main()
{
    char ch;
    while (scanf("%c", &ch) != EOF)
    {
        getchar();
        if (ch >= 'A' && ch <= 'Z')
        {
            printf("%c\n", ch + 32);
        }
        if (ch >= 'a' && ch <= 'z')
        {
            printf("%c\n", ch - 32);
        }
    }
    return 0;
}

````

---

## 变种水仙花

描述

> 变种水仙花数  - Lily Number：把任意的数字，从中间拆分成两个数字，比如1461 可以拆分成（1和461）,（14和61）,（146和1),如果所有拆分后的乘积之和等于自身，则是一个Lily Number。

例如：

> 655 = 6 * 55 + 65 * 5
>
> 1461 = 1 * 461 + 14 * 61 + 146*1
>
> 求出 5位数中的所有 Lily Number。

````c
#include<stdio.h>
int main()
{
    for(int i=10000;i<100000;i++)
    {  //五位数
        int a=0;                     
        int b=0;
        int c=10;
        int sum=0;
        int x=i;
        while(x/c!=0)
        {              
           a=x%c;                   //每一项乘法后部
           b=x/c;                   //每一项乘法前部
           sum+=a*b;                //项和
           c*=10;                   //下一位拆分，十位，百位.....
        }
      if(x==sum)
      {      
        printf("%d ",x);
      }
    }
  return 0;
}

````

````c
#include<stdio.h>
#include<math.h>

//变种水仙花数即
//eg: 1344 = 1 * 344 + 13 * 44 + 134 * 1;
//eg: 156  = 1 * 56 + 15 * 6;  结果成立即为变种水仙花数

int main()

{
	int i = 0, j = 0;

	for (i = 10000; i < 99999; i++)
	{
		int sum = 0;
		for (j = 1; j <= 4; j++)
		{
			int k = (int)pow(10, j);
			sum += (i / k) * (i % k);
		}
		if (sum == i)
		{
			printf("%d ", i);
		}
	}

	//int i, j = 0;

	//for (i = 0; i < 9; ++i)
	//{
	//	printf("%d ", i);
	//}

	return 0;
}
````

---

## 序列中删除指定数字

![<img src="C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20240516212837084.png" alt="image-20240516212837084" style="zoom:50%;" />](https://img-blog.csdnimg.cn/direct/6752a4a0c1f04997a5e818f4900acc16.png)






````c
#include <stdio.h>
 
int main()
{
    int n = 0;
    scanf("%d", &n);
    int arr[n];//C99
    //接收n个数字
    int i = 0;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int del = 0;
    //接收删除的值
    scanf("%d", &del);
    int j = 0;//j作为下标锁定的位置就是用来存放不删除的数据的
    for (i = 0; i < n; i++)
    {
        if (arr[i] != del)
        {
            arr[j++] = arr[i];
        }
    }
    for (i = 0; i < j; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
````



---

## 最高分与最低分之差

![<img src="C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20240516213638519.png" alt="image-20240516213638519" style="zoom:50%;" />](https://img-blog.csdnimg.cn/direct/850a3a32c05d483ba2f6f98ba72902a1.png)


**方法一**

>  冒泡排序将数组中的数重新排序一遍，然后最大的减去最小的得到最高分和最低分的差值
>
>  利用冒泡排序算法解决十个乱序数字排成升序数字

````c
void bubble_sort(int arr[100],int n)
{
	int i = 0;
	for (i = 0; i < n-1; i++)
	{
		//一趟冒泡排序
		int j = 0;
		for (j = 0; j < n - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = 0;
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
int main()
{
	int arr[100] = { 0 };
	int i = 0;
	int n = 0;
	scanf("%d",&n);
	for (i = 0; i < n; i++)
	{
		scanf("%d",&arr[i]);
	}
	bubble_sort(arr,n);
	int cha = arr[n - 1] - arr[0];
	printf("%d",cha);
	return 0;
}

````

**方法二**

> 传统方法，先设数组中的第一个数为最大值，然后遍历一遍数组中的数跟第一个数比较，如果都小于，则第一个数最大，如果比第一个数大，此时大的值为最大的。相同方法求出最小值

````c
int main()
{
	int n = 0;
	scanf("%d",&n);
	int arr[50] = { 0 };
	int i = 0;
	for (i = 0; i < n; i++)
	{
		scanf("%d",&arr[i]);
	}
	//求最大值
	int max = arr[0];
	for (i = 1; i < n; i++)
	{
		if (arr[i] > max) 
			max = arr[i]; 
	}
	//求最小值 
	int min = arr[0]; 
	for (i = 1; i < n; i++) 
	{
		if (arr[i] < min) 
			min = arr[i]; 
	}
	printf("%d",max-min); 
	return 0; 
}

````

**方法三**

> 建立在方法三的基础之上的，我们看到方法二中的代码求最大值和最小值分别用了两次遍历，加长了代码的长度和重复性，所以在这里我们可以简化一下，在求最大值的时候同时也在求最小值，这样就只需要遍历一遍就可以同时得到最大值和最小值了

````c
int main()
{
	int n = 0;
	scanf("%d", &n);
	int arr[50] = { 0 };
	int i = 0;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	//求最大值和最小值
	int max = arr[0];
	int min = arr[0];
	for (i = 1; i < n; i++)
	{
		if (arr[i] > max)
			max = arr[i];
		if (arr[i] < min)
			min = arr[i];
	}
	printf("%d", max - min);
	return 0;
}

````

**方法四**

> **方法四又是建立在方法三之上的**，在方法三的基础上我们发现我们是在所有数全部输入之后才进行遍历找出最大值，此时我们思考一下是不是可以在输入的时候就可以便输入便求出最大值呢，首先在题目中我们规定了最大不能超过100，最小不能低于0，所以在这里我们可以现设最小值就是100，然后在输入中，如果小于100的话，那么此时那个值就是最小值，如果后面还有更小的，又可以将它赋值给最小值，同理设最大值为0，可以同时在输入的时候求出最大值。

````c
nt main()
{
	int n = 0;
	scanf("%d", &n);
	int arr[50] = { 0 };   
	int i = 0;    
	int min = 100;    
	int max = 0;    
	for (i = 0; i < n; i++)    
	{
		scanf("%d", &arr[i]);    
		if (arr[i] > max)    
			max = arr[i];    
		if (arr[i] < min)    
			min = arr[i];    
	}
	printf("%d", max - min);    
	return 0;    
}


````

---

## 写一个函数返回参数二进制1的个数

````c
#include<stdio.h>

int find_1(unsianed int x)
{
    int count = 0;
    
    while(x)
    {
        if(x%2 == 1)
        {
            count++;
        }
        x /= 2;
    }
    
    return count;
}

//按位计算
int count_num(int num)
{
    int count = 0;

    int i = 0;

    for (i = 0; i < 32; i++)
    {
        if (((num >> i) & 1) == 1)
        {
            count++;
        }
    }

    return count;
}
//         count
//1111 n     1
//1110 n-1
//1110 n     2
//1101 n-1    
//1100 n     3
//1001 n-1
//1000 n     4
//0111 n-1
//0000     

int count_num1(int num)
{
    int count = 0;
    while(n)
    {
        n = n & (n - 1);
        count++;
    }
    return count;
}
int main()
{
   
    unsigned int a;
    scanf("%u", &a);

    int ret = find_1(a);

    int b = count_num(a);

    printf("%d", ret);

    printf("\n%d", b);

    return 0;
}
````

---

## 求两个数二进制中不同位的个数 :bangbang:



![<img src="C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20240517142236384.png" alt="image-20240517142236384" style="zoom:43%;" />](https://img-blog.csdnimg.cn/direct/4e1134aaeb734bdb80ecf847b144c819.png)


````c
#include<stdio.h>

int count_diff_bit(int n , int m)
{
    int count = 0;
    
    int i = 0;
    
    for(i = 0; i < 32; i++)
    {
        if( ( ( n >> i ) &1 ) != ( ( m >> i) & 1 ) )
        {
            count++;
        }
    }
    
    return count;
}
//利用异或操作符
//相同为0 相反为1
int count_diff_bit1(int n , int m)
{
    int count = 0;
    
    int i = 0;
    int ret = m ^ n;
    
    while(ret)
    {
        ret = ret & (ret - 1);
        count++;
    }
    
    return count;
}

int main()
{
    int m,n = 0;
    
    scanf("%d %d", &m , &n );
    
    int ret = count_diff_bit(m , n);
    
    printf("%d\n", ret );
    
    retrun 0;
}
````





---



## 打印整数二进制的奇数位和偶数位



![<img src="C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20240517144156963.png" alt="image-20240517144156963" style="zoom:50%;" />](https://img-blog.csdnimg.cn/direct/a4f0f7073f104ceca93120f8da723f8e.png)


````c
#include<stdio.h>
//10
//00000000 00000000 00000000 00000010
//获取一个整数二进制序列中所有的偶数位和奇数位，分别打印出二进制序列
int main()
{
    int i = 0;
    int num = 0;
    
    scanf("%d", &num );
    
    //奇数
    for(i = 30; i >= 0; i-= 2)
    {
        printf("%d ", (num >> i) & 1);
    }
    
    printf("\n");
    
     //偶数
    for(i = 31; i >= 1; i-= 2)
    {
        printf("%d ", (num >> i) & 1);
    }
    
    return 0;
}
````

---



## X形图案

![<img src="C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20240517145859645.png" alt="image-20240517145859645" style="zoom:50%;" />](https://img-blog.csdnimg.cn/direct/10d984a460294dcebc05266508bb93f0.png)





````c
#include<stdio.h>

int main()
{
    int n = 0;
    
    scanf("%d", &n );
    
    int i,j = 0;
    
    for(i = 0; i <= n; i++)
    {
        for(j = 0; j <= n; j++)
        {
            if(i == j || i + j == 5 )
            {
                printf("*");
            }
            else
                printf(" ");
        }
        
        printf("\n");
    }
    
    
    return 0;
}
````

---

## 三角形判断 :triangular_ruler:



![<img src="C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20240517153453393.png" alt="image-20240517153453393" style="zoom:50%;" />](https://img-blog.csdnimg.cn/direct/8d031484cfbd4cc8a880100916c960bb.png)



````c
#include<stdio.h。

int main()
{
    int a,b,c = 0;
    while(scanf("%d %d %d"),&a, &b, &c) == 3)
    {
        if((a+b>c) && (b+c>a) && (a+c>b))
        {
            if(a == b && b ==c)
            {
                printf("Equilateral triangle!\n"); // 等边
            }
            
            if( (a == b && b!= c) || (a ==c && c != b) || (b == c && b != a) )
            {
                printf("Isosceles triangle!\n"); //等腰
            }
            
            else
                printf("Ordinary triangle!\n"); // 普通
        }
    }
    
    
    return 0;
}
````

---

## 获得月份天数



![<img src="C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20240517151658686.png" alt="image-20240517151658686" style="zoom:50%;" />](https://img-blog.csdnimg.cn/direct/49abf5e15892469088a8d2caaf7bd0a4.png)


````c
#include<stdio.h>

int main()
{
    int y = 0;//年
    iny m = 0;//月
    int days[13] = {0,31,29,31,30,31,31,30,31,30,31,30,31};//1~12月 每月天数
    int day = 0;
    
    while (~scanf(("%d %d"), &y, &m) )
    {
        day = days[m];
        //闰年二月多一天
        if((y % 4 == 0 || y % 100 != 0) && ( y % 400 == 0))
        {
            day += 1;
        }
        
        printf("%d", day);
        
        return -1;
    }
    
    return 0;
}
````

---

## 逆序打印字符串



![在这里插入图片描述](https://img-blog.csdnimg.cn/direct/764887a91a8d47c8981f725cb5962004.png)



````c
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<assert.h>

void reverse(char* left, char* right)
{ 
	//断言 指针为空立即跳出
	assert(left);
	assert(right);

	while (left < right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}

int main()
{
	//输入
	char arr[101] = { 0 };

	gets(arr);

	int len = strlen(arr);

	//逆置
	reverse(arr, arr + len - 1);
	
	char* start = arr;

	while (*start)
	{
	
		char* end = start;

		while (*end != ' ' && *end != '\0')
		{
			end++;
		}

		reverse(start, end - 1);

		if (*end != '\0')
			end++;

		start = end;
	}


	//输出

	printf("%s\n\n", arr);

	return 0;
}
````

---

## 计算求和

![<img src="C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20240517162456895.png" alt="image-20240517162456895" style="zoom:50%;" />](https://img-blog.csdnimg.cn/direct/b7417ba41fee45f5a264a9713b200655.png)


````c
#include<stdio.h>


int main()
{
    int a,n = 0;
    scanf("%d %d", &a, &n);
    
    int sum = 0;
    int i = 0;
    int k = 0;
    for(i = 0; i < n; i++)
    {
        k = k * 10 + a;
        sum += k;
    }
    
    printf("%d\n",sum);
    
    return 0;
}
````

---

## 打印水仙花数



![<img src="C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20240517164725181.png" alt="image-20240517164725181" style="zoom:50%;" />](https://img-blog.csdnimg.cn/direct/fa6aa576eb844d92ad81bd082ef88b23.png)


````c
#include<stdio.h>

int main()
{
    int i = 0;
    for(i = 0; i <= 10000; i++)
    {
        //判断i是否为“水仙花数”
        //12345
        //1.计算i是几位数 -> n
        int n = 1; //任何一个数至少一位
        int tmp = i;
        int sum = 0;
        while(tmp/10)
        {
            n++;
            tmp /= 10;
        }
        //2.得到i每一位，计算它的n次方之和
        tmp = i;
        while(tmp)
        {
            sum += pow(tmp % 10, n);
            tmp /= 10;
        }
        
        if(sum == i)
        {
            printf("%d ",i);
        }
    }
    
    
    return 0;
}
````



````c
#include<stdio.h>

//100~1000 水仙花数
int main()
{
    int num = 100;

do
{
	int a = 0;
	int b = 0;
	int c = 0;

	a = num % 10;
	b = num / 10 % 10;
	c = num / 100;
	if (a * a * a + b * b * b + c * c * c == num)
	{
		printf("%d ",num);
	}

	num++;


} while (num < 1000);

    
    return 0;
}
````

````c
#include<stdio.h>


int main()
{
    //100~1000 水仙花数
	for (int num = 100; num < 1000; num++) {

		int a = 0;
		int b = 0;
		int c = 0;

		a = num % 10;
		b = num / 10 % 10;
		c = num / 100;


		if (num==a*a*a + b*b*b+ c*c*c)
        {
            printf("%d ",num);
        }

		
	}
}
````

---

## 菱形打印

![<img src="C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20240517171112229.png" alt="image-20240517171112229" style="zoom:60%;" />](https://img-blog.csdnimg.cn/direct/3e3a098038ae48699be0d29d53d847fb.png)



> ![<img src="C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20240517171548522.png" alt="image-20240517171548522" style="zoom:50%;" />](https://img-blog.csdnimg.cn/direct/844ffc18bac747208b9c2abd944eae98.png)



````c
#include<stdio.h>

int main()
{
	int i, j = 0;

	int line;

	scanf("%d", &line);

    //上
	for (i = 0; i < line; i++)
	{
		for (j = 0; j < line-i-1; j++)
		{
			printf(" ");
		}

		for (j = 0; j < (2*i)+1; j++)
		{
			printf("*");
		}

		printf("\n");

	}
    //下
	for (i = 0; i < line - 1; i++)
	{
		for (j = 0; j <= i; j++)
		{
			printf(" ");
		}

		for (j = 0; j < 2*(line-i-1)-1; j++)
		{
			printf("*");
		}

		printf("\n");
	}

	return 0;
}
````

---

## 喝汽水问题



![<img src="C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20240517172620505.png" alt="image-20240517172620505" style="zoom:50%;" />](https://img-blog.csdnimg.cn/direct/43de44a4cad747588d7376aa394bc07c.png)


> ![<img src="C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20240517173000670.png" alt="image-20240517173000670" style="zoom:50%;" />](https://img-blog.csdnimg.cn/direct/345ada75ced3412783c84ae2ab134c84.png)


````c
#include<stdio.h>

int main()
{
    int money;
      
    scanf("%d", & money);
    
    int total = monty;//喝了多少瓶
    int empty = money;//空瓶
    
    while(empty >= 2)//空瓶不少于两瓶能换汽水
    {
        total += empty / 2;//两个空瓶换一瓶
        empty = empty / 2 + empty % 2;//喝完还剩余换去的空瓶除二 + eg:（5/2) ~余一瓶~
    }
    
    printf("%d\n", total);
    // 20 39
    // 10 19
    
    //规律如下
    if(money > 0)
        printf("%d", 2*money - 1);
    else
        printf("%d", 0);
    
    return 0;
}
````

---

## 冒泡排序 :right_anger_bubble:

````c
#include<stdio.h>
void Bubble_sort(int arr[], int size)
{
	int j,i,tem;
	for (i = 0; i < size-1;i ++)//size-1是因为不用与自己比较，所以比的数就少一个
	{
		int count = 0;
		for (j = 0; j < size-1 - i; j++)	//size-1-i是因为每一趟就会少一个数比较
		{
			if (arr[j] > arr[j+1])//这是升序排法，前一个数和后一个数比较，如果前数大则与后一个数换位置
			{
				tem = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tem;
				count = 1;
				
			}
		}
		if (count == 0)			//如果某一趟没有交换位置，则说明已经排好序，直接退出循环
				break;	
	}
 
}
int main()
{
	int arr[10];
	int i;
	
	printf("请输入10个数\n");
	for (i = 0; i < 10; i++)		//接收用户的数值
	{
		scanf("%d", &arr[i]);
	}
	printf("排序前的数组>");
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
 
	printf("\n排序后的数组>");
	Bubble_sort(arr, 10);
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
 
	return 0;
}
````

---

## qsort函数排序 :soon:

### 1. [qsort](https://so.csdn.net/so/search?q=qsort&spm=1001.2101.3001.7020)()函数简介

> qsort（）函数是C语言库函数中的一种排序函数，排序方法为快速排序（quick sort） 。
>
> 其特点是可以排序任意类型的数组元素。
>
> ![<img src="C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20240518150947822.png" alt="image-20240518150947822" style="zoom:50%;" />](https://img-blog.csdnimg.cn/direct/5ef8f5b5361a4da7b74818981dd92b4c.png)



####  1.1 函数原型

> ![外链图片转存失败,源站可能有防盗链机制,建议将图片保存下来直接上传](https://img-blog.csdnimg.cn/direct/81d436a765c14c658128d266f1cb3d4c.png)


>
>```
>void qsort(void* base, 
>       size_t num, 
>       size_t size, 
>       int (*comparator)(const void* elem1, const void* elem2));
>```
>
>需引用头文件：<stdlib.h>或<search.h>

#### 1.2 函数参数 

> qsort（）函数需要四个参数 
>
> 1. void* base:  需排序数组首元素
> 2. size_t num: 数组元素个数
> 3. size_t size: 一个数组元素大小（byte）
> 4. int (*comparator) (const void* elem1 , const void* elem2):  是一个函数指针，其指向的是一个比较函数的地址，该函数有两个void* 的参数，其返回类型为int 。
>
> **void\* 类型指针：可以接收任意类型的地址，但不能进行解引用操作和不能对其进行加减整数的操作。**



### 2.比较函数简介

#### 2.1比较函数参数 
 > 比较函数为自定义函数：其两个参数为void*类型指针的elem1和elem2 ，返回参数为整形int
 >
 > 参数类型为void原因：不清楚需比较元素的类型是什么，所以通过void*类型指针的特点（可以接收任意类型的地址）来接收。const修饰其两个比较参数不可被更改
 >
 > 
 >
 > 返回值有三种情况： 
 >
 > ![<img src="C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20240518151845480.png" alt="image-20240518151845480" style="zoom:67%;" />](https://img-blog.csdnimg.cn/direct/9f2ce20ed0c34582ad929158d285eaaf.png)

 >
 >>  < 0 : elem1 小于 elem2
 >>
 >>  = 0 : elem1 等于 elem2
 >>
 >>  0 : elem1 大于 elem2

#### 2.2 比较函数使用 

> 如需使用比较函数而void*类型指针不能解引用操作和加减整数操作我们只需对两个元素进行**强制类型转换**为我们想比较元素的类型指针，再进行**解引用**获取两个元素的值，最后进行两个元素的**差值返回**。
>
> **整型数组**
>
> ```
> int comp_int(const void* elem1, const void* elem2)
> {
> 	return *(int*)elem1 - *(int*)elem2;
> }
> ```
>
> **字符数组**
>
> ```
> int comp_char(const void* elem1, const void* elem2)
> {
> 	return *(char*)elem1 - *(char*)elem2;//字符计算是计算ASCLL值
> }
> ```
>
> **浮点型数组**
>
> ```
> int comp_double(const void* elem1, const void* elem2)
> {
> 	return (int)(*(double*)elem1 - *(double*)elem2);
> //浮点型差值为浮点型，而返回值需要为int型，避免报错将差值强制类型转换为int型
> }
> ```
>
> **字符串**
>
> 按首字母排序
>
> ```
> int comp_char(const void* elem1, const void* elem2)
> {
> 	return *(char*)elem1 - *(char*)elem2;//字符计算是计算ASCLL值
> }
> ```
>
> **按字符串长度排序**
>
> ```
> int comp_string(const void* elem1, const void* elem2)
> {
> 	if (strlen(*(char*)elem1) > strlen(*(char*)elem2))
> 	{
> 		return 1;
> 	}
> 	else if (strlen(*(char*)elem1) < strlen(*(char*)elem2))
> 	{
> 		return -1;
> 	}
> 	else
> 	{
> 		return 0;
> 	}
> }
> ```
>
> **按正常排序**
>
> ```
> int comp_string(const void* elem1, const void* elem2)
> {
> 	return strcmp(*(char*)elem1, *(char*)elem2);//strcmp比较两个字符串大小
> }
> ```
>
> **结构体**
>
> ```
> struct stu
> {
> 	char name[20];
> 	int grade;
> };
> ```
>
> **对学生姓名排序**
>
> ```
> int comp_string(const void* elem1, const void* elem2)
> {
> 	return strcmp(((str*)elem1)->name, ((str*)elem2)->name);
> }
> ```
>
> **对学生成绩排序**
>
> ```
> int comp_string(const void* elem1, const void* elem2)
> {
> 	return strcmp(((str*)elem1)->grade, ((str*)elem2)->grade);
> }
> ```

### 3. qsort()函数使用 

#### 3.1 整形[数组排序](https://so.csdn.net/so/search?q=数组排序&spm=1001.2101.3001.7020)

> ```
> int cmp_int(const void* elem1, const void* elem2)
> {
> 	return *(int*)elem1 - *(int*)elem2;
> }
> int main()
> {
> 	int arr[] = { 2,4,6,8,10,1,3,5,9,7 };
> 	int sz = sizeof(arr) / sizeof(arr[0]);
> 	int i = 0;
> 	qsort(arr, sz, sizeof(arr[0]), cmp_int);
> 	for (i = 0; i < sz; i++)
> 	{
> 		printf("%d ", arr[i]);
> 	}
> 	return 0;
> }
> ```
>
> 

#### 3.2 字符数组排序

> ```
> int cmp_char(const void* elem1, const void* elem2)
> {
> 	return *(char*)elem1 - *(char*)elem2;
> }
> int main()
> {
> 	char ch[] = {'b','c','a','e','f','d','g'};
> 	int sz = sizeof(ch) / sizeof(ch[0]);
> 	int i = 0;
> 	qsort(ch, sz, sizeof(ch[0]), cmp_char);
> 	for (i = 0; i < sz; i++)
> 	{
> 		printf("%c ", ch[i]);
> 	}
> 	return 0;
> }
> ```
>
> 

#### 3.3 浮点型数组排序（double类型为例）

```
int cmp_double(const void* elem1, const void* elem2)
{
	return (int)(*(double*)elem1 - *(double*)elem2);
}
int main()
{
	double arr[] = {2.5,1.0,3.5,4.5,2.0};
	int sz = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	qsort(arr, sz, sizeof(arr[0]), cmp_double);
	for (i = 0; i < sz; i++)
	{
		printf("%f ", arr[i]);
	}
	return 0;
}
```

#### 3. 4 [字符串数组](https://so.csdn.net/so/search?q=字符串数组&spm=1001.2101.3001.7020)排序 

> 按字符串首字母排序
>
> ```
> int cmp_string(const void* elem1, const void* elem2)
> {
> 	return *(char*)elem1 - *(char*)elem2;
> }
> int main()
> {
> 	char ch[5][10] = { "black","cat","apple","face","dog" };
> 	int sz = sizeof(ch) / sizeof(ch[0]);
> 	int i = 0;
> 	qsort(ch, sz, sizeof(ch[0]), cmp_string);
> 	for (i = 0; i < sz; i++)
> 	{
> 		printf("%s ", ch[i]);
> 	}
> 	return 0;
> }
> ```
>
> 按正常排序
>
> ```
> int cmp_string(const void* elem1, const void* elem2)
> {
> 	return strcmp((char*)elem1,(char*)elem2);
> }
> int main()
> {
> 	char ch[5][10] = { "aaa","a","aaaaa","aa","aaaa" };
> 	int sz = sizeof(ch) / sizeof(ch[0]);
> 	int i = 0;
> 	qsort(ch, sz, sizeof(ch[0]), cmp_string);
> 	for (i = 0; i < sz; i++)
> 	{
> 		printf("%s ", ch[i]);
> 	}
> 	return 0;
> }
> ```

#### 3.5 结构体 

> ```
> typedef struct Stu
> {
> 	char name[20];
> 	int age;
> }Stu;
> 
> int cmp_str(const void* elem1, const void* elem2)
> {
> 	return strcmp(((Stu*)elem1)->name, ((Stu*)elem2)->name);
> }
> 
> int main()
> {
> 	Stu s[] = { {"张三",18},{"李四",19},{"王五",20} };
> 	int sz = sizeof(s) / sizeof(s[0]);
> 	int i = 0;
> 	qsort(s, sz, sizeof(s[0]), cmp_str);
> 	for (i = 0; i < sz; i++)
> 	{
> 		printf("%s %d\n", s[i].name, s[i].age);
> 	}
> 	return 0;
> }
> ```

---

## 【C语言】指针经典笔试八题 :accept:

> ## 前言
>
> 指针往往是变幻莫测，灵活多变，只有深入理解其本质才能有深刻的体会。
>
> 下面通过八道经典笔试题，来一起深入理解指针的神奇之处。 

### 笔试题1 

 **程序运行的结果是什么呢？**

> ```
> int main()
> {
> 	int a[5] = { 1, 2, 3, 4, 5 };
> 	int* ptr = (int*)(&a + 1);
> 	printf("%d,%d", *(a + 1), *(ptr - 1));
> 
> 	retrun 0;
> }
> ```
>
> **答案**
>
> ![<img src="C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20240518154202421.png" alt="image-20240518154202421" style="zoom:50%;" />](https://img-blog.csdnimg.cn/direct/672a68accf71453f85207dd676983301.png)

>
>**为什么会这样呢？**
>
>**详细解释如下：**
>
>![<img src="C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20240518154433571.png" alt="image-20240518154433571" style="zoom:67%;" />](https://img-blog.csdnimg.cn/direct/0fba1115706b4e24a7eb368345fa8a49.png)

>
>**（a + 1） - 解释：**
>
>                        就不再过多解释。
>
>***（ptr - 1） - 解释·：**
>
>     &a表示取整个数组的地址，对其加一跳过整个数组，指针指向了红色箭头指向的位置，但是这个指针又被强制类型转换成了整形(int*)类型的指针，并存放在ptr这个整形指针变量里面去了。
>
>此时的ptr指针就是一个整形指针，对其减一就是向前跳动一个整形的地址指向了蓝色箭头的位置，*(ptr - 1)是以整形指针的视角去读取所指空间的内容，也就是从蓝色箭头的指针处向后访问一个整形（4个字节）的长度，所以读到的就是5。

###  **笔试题2**

 ***\*程序运行的结果是什么呢？\****

***\*备注：\****

**//p是结构体指针
//假设p 的值为0x100000。 如下表表达式的值分别为多少？
//已知，结构体Test类型的变量大小是20个字节**

```
struct Test
{
	int Num;
	char* pcName;
	short sDate;
	char cha[2];
	short sBa[4];
}*p;
 
int main()
{
	p = (struct Test*)0x100000;
	printf("%p\n", p + 0x1);
	printf("%p\n", (unsigned long)p + 0x1);
	printf("%p\n", (unsigned int*)p + 0x1);
 
	return 0;
}
```

> **答案：**
>
> ![<img src="C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20240518154727554.png" alt="image-20240518154727554" style="zoom:50%;" />](https://img-blog.csdnimg.cn/direct/182570bdbe4444319011a89d9b48427d.png)

>
>**为什么会这样呢？**
>
>**详细解释如下：**
>
>计算机内存十一字节划分的，一个字节都有一个对应的地址，地址是由16进制来表示的。
>
>printf("%p\n", p + 0x1); - 解释：
>
>p = (struct Test*)0x100000;
>
>是将**0x100000** 强制类型转换成**(struct Test*)**这个结构体的地址。
>
>而我们知道指针的类型决定了指针加减整数的时候跳过的字节数；
>
>如：**int***类型的指针 **+ 1** 跳过4个字节，
>
>   **char*** 类型的指针 + 1跳过1个字节，
>
>所以结构体类型的指针 + 1 就跳过一个结构体。
>
>因为这个结构体的大小为20个字节，+1之后指针就向后跳20个字节，20的16进制是14 
>
>所以结果就为00100014。
>
>**printf("%p\n", (unsigned long)p + 0x1); - 解释：**
>
>**(unsigned long)p**   是将这个结构体的地址强制类型转换成无符号整形
>
>整形数字 + 1就是+1，所以结果是00100001。
>
>**printf("%p\n", (unsigned int*)p + 0x1); - 解释：**
>
>**(unsigned int*)p**  是将p强制类型转换成整形指针，整形指针+1就是跳过四个字节，
>
>所以结果是00100004。

> **补充**
>
> ---
>
> 
>
> 大小端存储：
>
> 全称：大端字节序存储    小端字节序存储
>
> 大端字节序存储：
>
> 当一个数据的低字节的数据存放在高地址处，高字节的内容放在了低地址处
>
> 这样的存储方式就是大端字节序的存储。
>
> 小端字节序存储：
>
> 当一个数据的低字节的数据存放在低地址处，高字节的内容放在了高地址处
>
> 这样的存储方式就是小端字节序的存储。
>
> 写一个小程序来判断当前机器的字节序是大端还是小端：
>
> ```
> int check_sys()
> {
> 	int a = 1;
> 	return *((char*)&a);//拿到的是低地址
> }
> 
> int main()
> {
> 	int ret = check_sys();//返回1是小端，返回0是大端
> 	if (1 == ret)
> 	{
> 		printf("小端\n");
> 		//低字节放在了低地址处
> 	}
> 	else if (0 == ret)
> 	{
> 		printf("大端\n");
> 		//高字节放在了低地址处
> 	}
> 	return 0;
> }
> ```
>
> 临时变量存放在栈区，栈区使用地址的习惯是从高地址到低地址。
>
> 32位平台下，1的存储。
>
> 二进制：00000000000000000000000000000001
>
> 十六进制：00 00 00 01
>   char* p = (char*)&a; - 将整形指针强制类型转换成字符指针。
>  *p;访问第一个字节（低字节向高字节读取）， 所以 *p 就拿到了低字节的存储数据。
>
> **小端存储示意图：**
>
> ![<img src="C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20240518155313476.png" alt="image-20240518155313476" style="zoom:50%;" />](https://img-blog.csdnimg.cn/direct/6634084a78c2454593d8db23edd9f452.png)

>
>**大端存储示意图：**
>
>![<img src="C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20240518155356085.png" alt="image-20240518155356085" style="zoom:50%;" />](https://img-blog.csdnimg.cn/direct/b2b9b92ae7f54e3e99e71407bc4fe6b7.png)


### 笔试题3 

 ***\*程序运行的结果是什么呢？\****

> ```
> int main()
> {
> 	int a[4] = { 1, 2, 3, 4 };
> 	int* ptr1 = (int*)(&a + 1);
> 	int* ptr2 = (int*)((int)a + 1);
> 	printf("%x,%x", ptr1[-1], *ptr2);
> 
> 	return 0;
> }
> ```
>
> **答案:**
>
> ![<img src="C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20240518155532402.png" alt="image-20240518155532402" style="zoom:50%;" />](https://img-blog.csdnimg.cn/direct/17b795ded6894c909e74b9426a91d1ac.png)

>
>为什么会这样呢？
>
>**详细解释如下：**
>
>**注意：本题的输出方式为十六进制输出。**
>
>**ptr1[-1] - 解释：**
>
>**与笔试1类似，不再赘述。**
>
>***ptr2 - 解释：**
>
>**a是数组首元素的地址，是十六进制的，强制类型转换成整形(int)之后再 + 1**
>**再强转成整形指针，也就是在上几部操作后，a的地址数值加了1，地址加1**
>**就是向后偏移了一个字节。**
>
>**在VS的环境下：存储方式为小端存储**
>**ptr从 01 指向了后一个字节 00。**
>
>![<img src="C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20240518155658220.png" alt="image-20240518155658220" style="zoom:50%;" />](https://img-blog.csdnimg.cn/direct/1c1ae3f64db745b18a655b3635ffaa54.png)

>
>**(int\*)((int)a + 1)** 再将其强转成整形指针，再向后访问四个字节并以十六进制的方式输出，
>
>所以结果是：2 00 00 00。
>
>**以什么形式存储，就以什么形式输出，以小端存储方式存入，就以小端的方式输出。**

### 笔试题4

***\*程序运行的结果是什么呢？\****

> ```
> int main()
> {
> 	int a[3][2] = { (0, 1), (2, 3), (4, 5) };
> 	int* p;
> 	p = a[0];
> 	printf("%d", p[0]);
> 
> 	return 0;
> }
> ```
>
> **答案：**
>
> ![<img src="C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20240518155841811.png" alt="image-20240518155841811" style="zoom:50%;" />](https://img-blog.csdnimg.cn/direct/e319707c38a2409cbcc03c19ab5ff227.png)

>
>**为什么会这样呢？**
>
>**详细解释如下：**
>
>这道题很简单，逗号表达式是从左到右一次执行，并以**最后一个值作为整个表达式的值**。
>
>所以，数组内部布局为：
>0  1 
>
>2  3
>4  5
>
>所以p[0]就为第一个元素1。

### 笔试题5 

***\*程序运行的结果是什么呢？\****

> ```
> int main()
> {
> 	int a[5][5];
> 	int(*p)[4];
> 	p = a;
> 	printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);
> 
> 	return 0;
> }
> ```
>
> **答案:**
>
> ![<img src="C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20240518160227676.png" alt="image-20240518160227676" style="zoom:50%;" />](https://img-blog.csdnimg.cn/direct/74447053381d497eab3347d24e724154.png)

>
>详细解释如下：
>
>**p是一个数组指针，p能够指向的数组是4个元素，**
>
>**a 为二维数组的数组名，二维数组的数组名表示二维数组第一行的地址。**
>
>**同时二维数组可以理解为一位数组组成的数组。**
>
>**p = a;**
>
>那么p + 1是**向后跳了四个整形(int)16个字节。**
>
>详解图：
>
>![<img src="C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20240518160408659.png" alt="image-20240518160408659" style="zoom:50%;" />](https://img-blog.csdnimg.cn/direct/a7dbe33466764473890be5a518c433f8.png)

>
>> a[4][2]的地址比p[4][2]的地址高4，所以结果为-4；
>>
>> 计算机存数据是以补码的形式存储：
>>
>> -4的存储
>>
>> 100000000 00000000 00000000 00000100 - 原码
>>
>> 111111111 11111111 11111111 11111011 - 反码
>>
>> 111111111 11111111 11111111 11111100 - 补码
>>
>> 以%p的形式输出，就是以16进制的形式输出，结果为：FF FF FF FC。

### 笔试题6

**程序运行的结果是什么呢?**

> ```
> int main()
> {
> 	int aa[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
> 	int* ptr1 = (int*)(&aa + 1);
> 	int* ptr2 = (int*)(*(aa + 1));
> 	printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));
> 
> 	return 0;
> }
> ```
>
> **答案：**
>
> ![<img src="C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20240518160613861.png" alt="image-20240518160613861" style="zoom:50%;" />](https://img-blog.csdnimg.cn/direct/25b242b89bee4759ba5c42b1ecdf4c14.png)

>
>**详细解释如下：**
>
>**与前面几题有所雷同，再次不再过多赘述。**
>
>**只强调一点：&aa得到的是整个二维数组的地址，对其+ 1是跳过整个二维数组。**

### 笔试题7

**程序运行的结果是什么呢？**

> ```
> int main()
> {
> 	char* a[] = { "work","at","alibaba" };
> 	char** pa = a;
> 	pa++;
> 	printf("%s\n", *pa);
> 
> 	return 0;
> }
> ```
>
> **答案：**
>
> ![<img src="C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20240518160819305.png" alt="image-20240518160819305" style="zoom:50%;" />](https://img-blog.csdnimg.cn/direct/cceb059fcfb94ea587bec70dbc0faff0.png)

>
>**详细解释如下：**
>
>**注意：**
>
>形如 char* p = "abcdefg";这样的p为字符指针，存放的是字符串首元素的地址。同时它是   只 读 的 ，是不能被修改的。如果 *p = ‘w’；这样操作的话，编译器报警告。
>
>**（访问权限冲突）**
>
>![<img src="C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20240518160925350.png" alt="image-20240518160925350" style="zoom:50%;" />](https://img-blog.csdnimg.cn/direct/ca8278527e8d4434aa75106d601542bd.png)

>
>a[]就是一个指针数组，里面存放的都是字符指针。
>
>a是数组名是数组首元素的指针，char** pa;说明pa是个指针，这个指针指向的类型是个字符指针。
>
>pa++；就是相当于pa + 1，首元素向后跳动一个字符指针，便是"at"这个字符串的首地址。

### 笔试题8

> ```
> int main()
> {
> 	char* c[] = { "ENTER","NEW","POINT","FIRST" };
> 	char** cp[] = { c + 3,c + 2,c + 1,c };
> 	char*** cpp = cp;
> 	printf("%s\n", **++cpp);//*cp[1] -> *(c + 2) -> c[2]
> 	printf("%s\n", *-- * ++cpp + 3);
> 	printf("%s\n", *cpp[-2] + 3);//* 的优先级比 +的优先级第
> 	printf("%s\n", cpp[-1][-1] + 1);
> 
> 	return 0;
> }
> ```
>
> **答案：**
>
> ![<img src="C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20240518161143750.png" alt="image-20240518161143750" style="zoom:50%;" />](https://img-blog.csdnimg.cn/direct/dd5e18228b7742cb8eb2df42a14d1674.png)

>
>**详细解释如下：**
>
>**一开始布局：**
>
>![<img src="C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20240518161353688.png" alt="image-20240518161353688" style="zoom:50%;" />](https://img-blog.csdnimg.cn/direct/34b90b7c5d9d4ca7a7400a2a4411cca9.png)


>
>c中放的是字符串首地址。
>
>cp中放的是c中元素得地址。
>
>cpp放的是cp首元素地址。
>
>****++cpp - 解释：**
>
>补充：操作符的优先级：++ 高于 * 高于 + 高于 - 
>
>先对cpp自增一次，此时cpp指向了（c + 2）的位置，一次解引用*操作就拿到了cp数组中的（c + 2），再次解引用*操作就拿到了c数组中第3个元素，第三个是个元素是字符指针，这个字符指针存放的是POINT这个字符串的首地址，%s拿到了POINT首地址向后打印，所以结果为POINT。
>
>***-- * ++cpp + 3 - 解释：**
>
>cpp现在原只向的（c + 2）位置上自增1，此时指向了（c + 1）的位置上，解引用*一次便拿到了（c + 1），因为 -- 的优先级比+高，先执行 -- ，(c + 1)自减变成了c，再解引*用一次，就拿到c[]数组的第一个元素，第一个元素存的是ENTER的首地址，再对首地址 + 3，跳过三个字符，指向了E。%s拿到了E的地址向后打印，结果就是ER。
>
>***cpp[-2] + 3 - 解释：**
>
>*cpp[-2] + 3   <==> *(*(cpp - 2)) + 3,cpp在指向原来的（c + 1）位置,而（cpp - 2）向前跳动两个char**的元素指向了（c + 3）的位置，但是cpp本身的值没变，这时对（cpp - 2）解引用*一次就拿到了（c + 3），再对（c + 3）解引用*一次就拿到了c[]数组中的最后一个元素，c[]数组中的最后一个元素存的是FIRST字符串的首地址，对其+3就是跳过三个字符，指向了S。%s拿到了S的地址向后打印，结果就是ST。
>
>**cpp[-1][-1] + 1 - 解释：**
>
>cpp[-1][-1] + 1  <==>  *(*(cpp - 1) - 1) + 1,cpp在指向原来的（c + 1）位置,(cpp - 1)向前跳动一个char**的元素指向了（c + 2）的位置，但是cpp本身的值没变，这时对（cpp - 1）解引用*一次就
>
>拿到了(c + 2),再对（c + 2) - 1得到了（c + 1），再对（c + 1）解引用*一次就拿到了c[]数组中的第二个元素，c[]数组中的第二个元素存的是NEW这个字符串的首地址，对其 +1就是跳过一个字符，指向了E。%s拿到了E的地址向后打印，结果就是EW。 
>
>> **总结：** :pencil2:
>>
>> 指针往往比较灵活且多变，空想很难有想出答案，最好的方法就是：画图。
>>
>> 结合题目的要求找到对应关系，当把所有的关系理清时，会有一种拨开迷雾见青山的快感。
>
>---

## 小乐乐该数字

![<img src="C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20240518161802576.png" alt="image-20240518161802576" style="zoom:50%;" />](https://img-blog.csdnimg.cn/direct/6530f164bbd449e79fd4b636cbc8a894.png)


> **思路：**
>
> ![<img src="C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20240518163231488.png" alt="image-20240518163231488" style="zoom:40%;" />](https://img-blog.csdnimg.cn/direct/75967185b1944211ac5c3181ee623961.png)

> ---

```
#include<stdio.h>
#include<math.h>

int main()
{
    //输入
    int num = 0;
    scanf("%d", &num);//123
    //计算
    int tmp = 0;
    int i = 0;
    int sum = 0;
    while(num)
    {
    	tmp = num % 10;
    	if(tmp % 2 == 1)
    		tmp = 1;
    	else
    		tmp = 0;
    	sum += tmp * pow(10, i++);
    	num = num / 10;
    }
    
    //输出
    printf("%d\n", sum);
    
    return 0;
}
```

## 带空格直角三角形的图案

![<img src="C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20240518163823621.png" alt="image-20240518163823621" style="zoom:50%;" />](https://img-blog.csdnimg.cn/direct/80106e8de57f49c6a15758fd3197ef1e.png)


> **思路:**
>
> ![<img src="C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20240518163923235.png" alt="image-20240518163923235" style="zoom:60%;" />](https://img-blog.csdnimg.cn/direct/20a47fd29c4245d78d65a1e9657c21e2.png)

>
>---

```
#include<stdio.h>

int main()
{
/*	int i,j,n = 0;
	//输入
	scanf("%d", &n);
	
	for(i = 0; i <= n; i++)
	{
		for(j = n-1; j>=0; i--)
		{
			printf(" ");
		}
		for(j = 0; j <= n; i++)
		{
			printf("*");
		}
		printf("\n");
	}
*/
//--------------------------

	int i,j,n = 0;
	
	while(scanf("%d", &n) == 1)
	{
		for(i = 0; i < n; i++)
		{
			for(j = 0; j <n; j++)
			{
				if(i + j < n -1)
					printf(" ");
					
				else
					printf("*");
			}
			
			printf("\n");
		}
		
	}




	return 0;
}
```

## 网购

![<img src="C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20240518165153743.png" alt="image-20240518165153743" style="zoom:50%;" />](https://img-blog.csdnimg.cn/direct/2cc6fb4e642548139b97c0b438721ac7.png)


![<img src="C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20240518165254936.png" alt="image-20240518165254936" style="zoom:43%;" />](https://img-blog.csdnimg.cn/direct/fb43693982ca45a19e59855aa1aa241f.png)


> ```
> #include<stdio.h>
> 
> int main()
> {
> 	double price = 0.0;
> 	int m = 0;
> 	int d = 0;
> 	int flag = 0;
> 
> 	//输入
> 	scanf("%lf %d %d %d", &price, &m, &d, &flag);
> 	//计算
> 
> 	if(m == 11 && d == 11)
> 	{
> 		price = price * 0.7 - flag * 50；
> 	}
> 
> 	else if(m == 12 && d == 12)
> 	{
> 		price = price * 0.8 - flag * 50；
> 	}
> 
> 	//输出
> 	if(price < 0.0)
> 	{
> 		printf("%.2lf\n", 0);
> 	}
> 
> 	else
> 		printf("%.2lf\n", price);
> 
> 	return 0;
> }
> ```
>
> ---

## 确定比赛名次 :game_die:

![<img src="C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20240518170517140.png" alt="image-20240518170517140" style="zoom:50%;" />](https://img-blog.csdnimg.cn/direct/1ed8ee0b622b4690a714a73df87ce1eb.png)


> ```
> #include<stdio.h>
> 
> int main()
> {
> 	int a,b,c,d,e = 0;
> 
> 	for(a = 1; a <= 5; a++)
> 	{
> 		for(b = 1; b <= 5; b++)
> 		{
> 			for(c = 1; c <= 5; c++)
> 			{
> 				for(d = 1; d <= 5; d++)
> 				{
> 					for(e = 1; e <= 5; e++)
> 					{
> 						if(((b == 2) + (a == 3) = 1 ) && ((b == 2) + (e == 4) =1)                            &&((c == 1) + (d == 2) = 1) && ((c == 5) + (d == 3)= 1)                            &&((e == 4) + (a == 1) = 1) )
> 			            {
> 			            	//1*2*3*4*5 = 120;
> 			            	if( (a*b*c*d*e) == 120 )
>                          	printf("a=%d,b=%d,c=%d,d=%d,e=%d\n",a,b,c,d,e);		
> 			             }
> 					}
> 
> 				}
> 			}
> 		}
> 	}
> 
> return 0;
> }
> ```
>
> ---

## 谁是凶手 :knife:

![<img src="C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20240518174841410.png" alt="image-20240518174841410" style="zoom:43%;" />](https://img-blog.csdnimg.cn/direct/b9d6cb3db3554ee7bed7c2c0c2f7e09b.png)


> ```
> #include<stdio.h>
> 
> int main()
> {
> 	int killer = 0;
> 	for(killer = 'a'; killer <= 'd'; killer++)
> 	{
> 		if( (killer != 'a') + (killer == 'c') + (killer == 'd') +
> 		  (killer != 'd') == 3)
> 		{
> 				printf("%c\n", killer); 
> 		  }
> 	}
> 
> 
> retrurn 0;
> }
> ```
>
> ---

## 打印杨辉三角

![<img src="C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20240518180616503.png" alt="image-20240518180616503" style="zoom:50%;" />](https://img-blog.csdnimg.cn/direct/9f7a63afcb7e4167a24dd872d46a3901.png)



>  **思路：**![<img src="C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20240518180458697.png" alt="image-20240518180458697" style="zoom:50%;" />](https://img-blog.csdnimg.cn/direct/de71255a2c144ccbbb206944c130136b.png)


```
#include<stdio.h>
#include<string.h>
#include<assert.h>

//打印杨辉三角
//1
//1 1
//1 2 1
//1 3 3 1
//1 4 6 4 1
int main()
{
	int arr[10][10] = { 0 };

	int i, j= 0;

	for (i = 0; i <10; i++)
	{
		for (j = 0; j <= i; j++)  
		{
			if (j ==0)           //第一列为1
			{
				arr[i][j] = 1;
			}

			//1
			//  1
			//    1
			//      1
			if (i == j)          
			{
				arr[i][j] = 1;
			}
			if (i >= 2 && j >= 1)
			{
				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
			}
		}
	}

	for (i = 0; i < 10; i++)
	{	
		for (j = 0;j <= i; j++)
		{
			printf("%3d", arr[i][j]);
		}
		printf("\n");
	}

	return 0;
}
```

---

## 字符串左旋 :rewind:

![<img src="C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20240518181357927.png" alt="image-20240518181357927" style="zoom:50%;" />](https://img-blog.csdnimg.cn/direct/87110ff41fc443b1871238d969607f00.png)


> **思路：**![<img src="C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20240518182121569.png" alt="image-20240518182121569" style="zoom:33%;" />](https://img-blog.csdnimg.cn/direct/d8b47347ad2f488da2af9ea6792a2db5.png)


> ```
> #include<stdio.h>
> #include<string.h>
> 
> //实现一个函数，可以实现左旋转K个字符
> void left_rotate(char arr[], int k)
> {
> 	int i = 0;
> 	int len = (int)strlen(arr);
> 
> 	//if (k == len)
> 	//{
> 	//	return 1;
> 	//}
> 	//else if (k > len)
> 	//{
> 	//	k = k - len;
> 	//}
> 
> 	//如果k=6 即等于自身长度 -> 模6 = 0 没旋转
> 	k %= len;
> 
> 	for (i = 0; i < k; i++)
> 	{
> 		//旋转1个字符
> 		//1
> 		char temp = arr[0];
> 		int j = 0;
> 		//2
> 		for (j = 0; j < len - 1; j++)
> 		{
> 			arr[j] = arr[j + 1];
> 		}
> 		//3
> 		arr[len - 1] = temp;
> 	}
> }
> 
> 
> int main()
> {
> 	char arr[] = "abcdef";
> 	int k = 0;//2
> 			  //cdefab
> 	printf("请输入旋转值k:");
> 	scanf("%d", &k);
> 
> 	left_rotate(arr, 2);
> 
> 	printf("%s", arr);
> 
> 
> 
> 	return 0;
> }
> ```
>
> ---

>  **思路2：**![<img src="C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20240518182802930.png" alt="image-20240518182802930" style="zoom:50%;" />](https://img-blog.csdnimg.cn/direct/2c5540e4612440fc9c2fb9c9c41703cf.png)

>
>```
>#include<stdio.h>
>#include<string.h>
>#include<assert.h>
>
>//实现一个函数，可以实现左旋转K个字符
>
>void reverse(char* left, char* right)
>{
>	//断言 空指针跳出
>	assert(left && right);
>	while (left < right)
>	{
>		char tmp = *left;
>		*left = *right;
>		*right = tmp;
>		left++;
>		right--;
>	}
>}
>
>void left_rotate(char arr[], int k)
>{
>	int len = (int)strlen(arr);
>
>	//如果k=6 即等于自身长度 -> 模6 = 0 没旋转
>	k %= len;
>
>	//左
>	reverse(arr,arr + k - 1);
>	//右
>	reverse(arr + k, arr + len - 1);
>	//整体
>	reverse(arr, arr + len - 1);
>}
>
>int main()
>{
>	char arr[] = "abcdef";
>	int k = 0;//2
>			  //cdefab
>	printf("请输入旋转值k:");
>	scanf("%d", &k);
>
>	left_rotate(arr, 2);
>
>	printf("%s", arr);
>
>
>
>	return 0;
>}
>```
>
>---

## 杨氏矩阵

![<img src="C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20240518183329648.png" alt="image-20240518183329648" style="zoom:50%;" />](https://img-blog.csdnimg.cn/direct/531605c36d6b452b802762a7e94d77fb.png)


> **思路：**![<img src="C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20240518184524237.png" alt="image-20240518184524237" style="zoom:50%;" />](https://img-blog.csdnimg.cn/direct/a632e0c003ad4a46aa638dfa12580745.png)



> ```
> #include<stdio.h>
> 
> //杨氏矩形 ->  从左到右，上到下逐渐递增
> //  1  2  3
> //  4  5  6
> //  7  8  9
> 
> /*
> 
> *     1   2   3
> * 
> *     4   5   6
> * 
> *     7   8   9
> * 
> */
> 
> //struct  Point
> //{
> //	int x;
> //	int y;
> //
> //};
> 
> //struct Point find_num(char arr[3][3], int r, int w, int k)
> //{
> //	int x = 0;
> //	int y = w - 1;
> //	struct Point p;
> //	p.x = -1;
> //	p.y = -1;
> //	while (y >= 0 && x <= r - 1)
> //	{
> //		if (k < arr[x][y])
> //		{
> //			y--;
> //		}
> //		else if (k > arr[x][y])
> //		{
> //			x++;
> //		}
> //		else
> //		{
> //			p.x = x;
> //			p.y = y;
> //			//printf("下标为：%d   %d\n", x, y);
> //			return p;
> //		}
> //	}
> //	return  p;
> //}
> 
> int find_num(char arr[3][3], int* px, int* py, int k)
> {
> 	int x = 0;
> 	int y = *py - 1;
> 
> 	while (y >= 0 && x <= *px - 1)
> 	{
> 		if (k < arr[x][y])
> 		{
> 			y--;
> 		}
> 		else if (k > arr[x][y])
> 		{
> 			x++;
> 		}
> 		else
> 		{
> 			*px = x;
> 			*py = y;
> 			//printf("下标为：%d   %d\n", x, y);
> 			return 1;
> 		}
> 	}
> 	*px = -1;
> 	*py = -1;
> 	return  0;
> }
> 
> int main()
> {
> 	char arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
> 	printf("请输入你要查找的数->  ");
> 
> 	int k;
> 
> 	int x = 3;//行
> 
> 	int y = 3;//列
> 
> 	scanf("%d", & k);
> 
> 	int ret = find_num(arr, &x, &y, k);
> 
> 	if (ret == 1)
> 
> 		printf("%d   %d\n", x, y);
> 	else
> 		printf("找不到\n");
> 
> 	return 0;
> }
> ```
>
> ---

## 字符串旋转结果 

![<img src="C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20240518185846003.png" alt="image-20240518185846003" style="zoom:50%;" />](https://img-blog.csdnimg.cn/direct/3680c6910aac400ea00dc9176a7061fa.png)


> ```
> #include<stdio.h>
> #include<string.h>
> 
> int is_left_move(char arr1[], char arr2[])
> {
> 	int len = strlen(arr1);
> 	int i = 0;
> 	int j = 0;
> 	for(i = 0; i < len; i++)
> 	{
> 		char tmp = arr1[0];
> 		for(j = 0; j < len -1; j++)
> 		{
> 			arr1[j] =arr[j+1];
> 		}
> 		arr[len - 1] = tmp;
> 
> 		if(strcmp(arr2, arr1) == 0) //字符串想等
> 			return 1;
> 
> 		else
> 			return 0;
> 	}
> }
> 
> int main()
> {
> 	char arr1[] = "abcdef";
> 	char arr2[] = "cdefab";
> 
> 	int ret = is_left_move(arr1, arr2);
> 	if(ret == 1)
> 		printf("Yes\n");
> 
> 	else
> 		printf("No\n");
> 
> return 0;
> }
> ```
>
> ```
> #include<stdio.h>
> #include<string.h>
> 
> int is_left_move(char arr1[], char arr2[])
> {
> 	int len = strlen(arr1);
> 	//追加
> 	strncat(arr1, arr1, len);
> 	//字符串中查找子字符串
> 	char* ret = strstr(arr1, arr2);
> 
> 	if (ret == NULL)
> 	{
> 		return 0;
> 	}
> 	else
> 		return 1;
> }
> 
> int main()
> {
> 	char arr1[20] = "abcdef";
> 	char arr2[] = "cdefab";
> 
> 	//abcdefabcdef
> 	//bcdefa
> 	//cdefab
> 	//defabc
> 	//efabcd
> 	//fabcde
> 	//abcdef
> 
> 	int ret = is_left_move(arr1, arr2);
> 	if(ret == 1)
> 		printf("Yes\n");
> 
> 	else
> 		printf("No\n");
> 
> return 0;
> }
> ```
>
> ---

## 上三角矩阵判断 :computer:

![<img src="C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20240516154856886.png" alt="image-20240516154856886" style="zoom:50%;" />](https://img-blog.csdnimg.cn/direct/2af0557cc6574527884561464512e4b0.png)



![<img src="C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20240516155657901.png" alt="image-20240516155657901" style="zoom:50%;" />](https://img-blog.csdnimg.cn/direct/5826eff7a65c4c6ab56a59ff4828d4bf.png)


````C
#include<stdio.h>

int main()
{
    int m;
    scanf("%d",&m);
    
    int i = 0;
    int j = 0;
    int flag = 1;//是上三角矩形    
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < m ;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    
    //判断  
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < i ;j++)
        {
            if(arr[i][j]!= 0)
            {
                flag = 0;//不是上三角矩形
                goto end;
                    
            }
        }
    }
    
    end:
    	if(flag == 0)
            printf("No\n");
    	else
            printf("Yes\n");
    
    
    return 0;
}
````

---



## 矩形转阵 :cupid:



![在这里插入图片描述](https://img-blog.csdnimg.cn/direct/9962d08b088742478d5475934bc9284e.png)


````c
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main()
{
	//矩形转阵
	//输入n行m列  -> 输出m行n列
	//输入：  1  2  3
	//       4  5  6
	//输出：  1  4
	//       2  5
	//       3  6

	int n = 0;
	int m = 0;
	scanf("%d%d", &n, &m);

	int arr[10][10] = { 0 };
	int i, j = 0;

	//输入
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			scanf("%d", &arr[i][j]);
		}

	}
	
    //输出
    //列
	for (i = 0; i < m; i++)
	{
        //行
		for (j = 0; j < n; j++)
		{
			printf("%d ", arr[j][i]);
		}
		printf("\n");
	}


}
````

---