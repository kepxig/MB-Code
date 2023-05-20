
package c方法互调;

public class C2
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

	static int[] 合并数组(int[][] ges)
	{
		int zongChang = 0;
		for (int h = 0; h < ges.length; h++)
		{
			zongChang+=ges[h].length;
		}
		int[] shus = new int[zongChang];
		int xb =0;
		for (int h = 0; h < ges.length; h++)
		{
			for (int l = 0; l < ges[h].length; l++)
			{
				shus[xb++] = ges[h][l];
			}
		}
		return shus;
	}

	public static void main(String[] args)
	{
		int[][] fenShus = new int[][]
				{
						{56,78,76,59,60,100,97},
						{90,78,98,34,67,88,48,90},
						{55,44,99,64,12, 8,100,56}
				};

		int[] shus = 合并数组(fenShus);
		排序(shus,false);
		for (int xb = 0; xb < shus.length; xb++)
		{
			System.out.print(  shus[xb]+"\t" );
		}
	}
}
