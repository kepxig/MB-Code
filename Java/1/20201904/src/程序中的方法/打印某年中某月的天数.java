

package 程序中的方法;

public class 打印某年中某月的天数
{
	public static void main(String[] args)
	{
		int nian=2008;
		int yue=2;
		switch (yue)
		{
			case 1:
				System.out.println("31");//换行：println    不换行：去掉ln
				break;
			case	2://是不是闰年
				if(nian%4==0)//如果
				{
					System.out.println("29");//打印
				}
				else//否则
				{
					System.out.println("28");//打印
				}
				break;//跳出;
			case 3:
				System.out.println("31");//换行：println    不换行：去掉ln

				break;
			case 4:
				System.out.println("30");//换行：println    不换行：去掉ln

				break;
			case 5:
				System.out.println("31");//换行：println    不换行：去掉ln

				break;
			case 6:
				System.out.println("30");//换行：println    不换行：去掉ln

				break;
			case 7:
				System.out.println("31");//换行：println    不换行：去掉ln

				break;
			case 8:
				System.out.println("31");//换行：println    不换行：去掉ln

				break;
			case 9:
				System.out.println("30");//换行：println    不换行：去掉ln

				break;
			case 10:
				System.out.println("31");//换行：println    不换行：去掉ln

				break;
			case 11:
				System.out.println("30");//换行：println    不换行：去掉ln

				break;
			case 12:
				System.out.println("31");//换行：println    不换行：去掉ln

				break;

		}
	}
}
