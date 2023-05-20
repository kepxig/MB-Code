
package 程序中的方法;

public class 计算器
{
	public static void main(String[] args)
	{
		int shuA = 100;

		int shuB = 50;

		int he = shuA+shuB;
		System.out.println("和="+he);

		int cha = shuA-shuB;
		System.out.println("差="+cha);

		int ji = shuA*shuB;
		System.out.println("积 ="+ ji);

		double shang = shuA/1.0/shuB;
		System.out.println("商=" + shang);

		int yuShu = shuA%shuB;
		System.out.println("余数="+yuShu);
	}
}
