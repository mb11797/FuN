package hackerblocks;

import java.util.Scanner;

public class Smart_Keypad_Advance {
	static String SearchIn[]= {
            "prateek", "sneha", "deepak", "arnav", "shikha", "palak",
            "utkarsh", "divyam", "vidhi", "sparsh", "akku"
    };

	public static void main(String[] args) {
		Scanner scn=new Scanner(System.in);
		String n=scn.next();
		printstrings(n,"");

	}

	public static String getString(char ch)
	{
		if(ch=='1')
		{
			return "..";
		}
		else if(ch=='2')
		{
			return "abc";
		}
		else if(ch=='3')
		{
			return "def";
		}
		else if(ch=='4')
		{
			return "ghi";
		}
		else if(ch=='5')
		{
			return "jkl";
		}
		else if(ch=='6')
		{
			return "mno";
		}
		else if(ch=='7')
		{
			return "pqrs";
		}
		else if(ch=='8')
		{
			return "tuv";
		}
		else if(ch=='9')
		{
			return "wxyz";
		}
		else
		{
			return "";
		}
	}
	public static void printstrings(String str,String osf)
	{
		if(str.length()==0)
		{
			for(String ss:SearchIn)
			{
				if(ss.contains(osf))
				{
					System.out.println(ss);
				}

			}
			return;
		}

		char cc=str.charAt(0);
		String ros=str.substring(1);
		String code=getString(cc);
		for(int i=0;i<code.length();i++)
		{
			printstrings(ros,osf+code.charAt(i));
		}
	}

}
