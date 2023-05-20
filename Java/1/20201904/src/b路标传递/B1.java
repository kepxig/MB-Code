
package b路标传递;

public class B1
{
	static void 打乱(int[][] ges)
	{
		for (int i = 0; i < 10; i++)
		{
			int h1 = (int) (Math.random()*ges.length);
			int l1 = (int) (Math.random()*ges[h1].length);
			int h2 = (int) (Math.random()*ges.length);
			int l2 = (int) (Math.random()*ges[h2].length);
			int t;
			t = ges[h1][l1];
			ges[h1][l1]=ges[h2][l2];
			ges[h2][l2] = t;
		}
	}
	public static void main(String[] args)
	{
		int[][] shus = new int[][]
				{
						{1,2,3,4,5},
						{10,20,30,40,50},
						{100,200,300,400,500},
				};

		打乱(shus);

		for (int h = 0; h < shus.length; h++)
		{
			for (int l = 0; l < shus[h].length; l++)
			{
				System.out.print(shus[h][l]+"  ");
			}
			System.out.println();
		}
	}
}
