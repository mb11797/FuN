import java.util.Scanner;
public class PrimeVisit2
{
    static int sieveOfEratosthenes(int n, int l)
    {
    	int count = 0;
        boolean prime[] = new boolean[n+1];
        for(int i=0;i<n;i++)
            prime[i] = true;

        prime[0] = false;
        prime[1] = false;

        for(int p = 2; p*p <=n; p++)
        {
        	if(prime[p] == true)
            {
                for(int i = 2; i * p <= n; i++)
                    prime[i * p] = false;
            }
        }

         for(int i = l; i <= n; i++)
        {
            if(prime[i] == true)
                count++;
        }
         return count  ;
    }

    public static void main(String args[])
    {
    	Scanner sr = new Scanner(System.in);
    	int t = sr.nextInt();

    	// input loop
    	for(int i = 1; i <= t ; i++)
    	{
    		int l = sr.nextInt();
            int m = sr.nextInt();
            System.out.println(sieveOfEratosthenes(m, l));
     	}

    }
}
