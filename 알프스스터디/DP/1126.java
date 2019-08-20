import java.util.*;
class Main
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int num = sc.nextInt();
		int[] arr = new int[num];
		for(int i = 0; i<num; i++)
			arr[i] = sc.nextInt();

		Arrays.sort(arr);
		
				
	}
}	

class a
{
	public static int find(int[] arr, int num)
	{
		int a1 = 0;
		int[] arr1 = new int[num];
		int a2 = 0;
		int[] arr2 = new int[num];
		int idx = num-1;

		while(idx >= 0)
		{
									