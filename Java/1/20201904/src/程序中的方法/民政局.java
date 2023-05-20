

package 程序中的方法;

public class 民政局
{
	public static void main(String[] args)
	{

		int nian=21;
		boolean xing=false;//布尔  true false
		boolean xingMa ;
		//办理结婚
		if (xing)
		{
			if (nian>=22)
			{
				xingMa = true;
			}
			else
			{
				xingMa = false;
			}
		}
		else
		{
			if (nian>=20)
			{
				xingMa = true;
			}
			else
			{
				xingMa = false;
			}
		}
		System.out.println(xingMa);

	}
}
