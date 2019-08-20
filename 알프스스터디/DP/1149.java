import java.util.Scanner;
class Main
{
	public static int Min(int a1, int a2)
	{
		if(a1<a2)
			return a1;
		else
			return a2;
	}
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int num = sc.nextInt();
		int[][] arr = new int[num][3];
		for(int i = 0; i<num; i++)
			for(int j = 0; j<3; j++)
				arr[i][j] = sc.nextInt();
	
		int[][] arr1 = new int[num][3];
		arr1[0][0] = arr[0][0];
		arr1[0][1] = arr[0][1];
		arr1[0][2] = arr[0][2];
		int a, b, c;
		for(int i = 1; i<num; i++)
		{
			a = arr1[i-1][0]; b = arr1[i-1][1]; c = arr1[i-1][2];		
			for(int j = 0; j<3; j++)	
			{
				if(j == 0)
					arr1[i][j] = Min(b,c);
				else if(j == 1)
					arr1[i][j] = Min(a,c);
				else
					arr1[i][j] = Min(a,b);

				arr1[i][j] += arr[i][j];
			}
		}

		int ret = Min(arr1[num-1][0], arr1[num-1][1]);
		ret = Min(ret, arr1[num-1][2]);		
		System.out.println(ret);
	}
}