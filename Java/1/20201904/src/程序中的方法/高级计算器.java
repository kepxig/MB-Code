

package 程序中的方法;

public class 高级计算器
{
	public static void main(String[] args)
	{
		int[] shus = new int[]{1,2,4,56,7,8,9,0};

		int he = 0;
		for ( int i=0;i<shus.length;i++)
		{
			he=he+shus[i];
		}

		System.out.println(he);
	}

}
