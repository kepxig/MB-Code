
package b路标传递;

public class B2
{
	static void 排序(int[] shus,boolean sheng )
	{
		for (int s = 0; s < shus.length-1; s++)
		{
			for (int b = s+1; b < shus.length; b++)
			{
				if ( sheng ==true)
				{
					if (shus[s]>shus[b])
					{
						int t = shus[s];
						shus[s] = shus[b];
						shus[b] = t;
					}
				}
				else
				{
					if (shus[s]<shus[b])
					{
						int t = shus[s];
						shus[s] = shus[b];
						shus[b] = t;
					}
				}
			}
		}
	}

	public static void main(String[] args)
	{
		//数组引用---指向--->数组对象s
		int[] nianLings = {10,6,8,39,12,4,21,45};
		排序(nianLings,true);
		for (int xb = 0; xb < nianLings.length; xb++)
		{
			System.out.print( nianLings[xb]+"\t" );
		}
		System.out.println();
		System.out.println();


		int[][] fenShus = new int[][]
				{
						{56,78,76,59,60,100,97},
						{90,78,98,34,67,88,48,90},
						{55,44,99,64,12, 8,100,56}
				};
		for (int h = 0; h <fenShus.length; h++)
		{
			排序(fenShus[h],false);
		}

		for (int h = 0; h < fenShus.length; h++)
		{
			for (int l = 0; l < fenShus[h].length; l++)
			{
				System.out.print( fenShus[h][l]+"\t" );
			}
			System.out.println();
		}


	}
}
