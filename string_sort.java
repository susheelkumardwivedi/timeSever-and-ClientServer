import java.util.Scanner;

class Sort{
	public static void main(String[] args){
		Scanner sc= new Scanner(System.in);
		System.out.println("Enter String");
		String input=sc.next();
		System.out.println("Original string is\n"+input);
		String output=sortString(input);
		System.out.println("After Sort string\n"+output);
	}
	public static String sortString(String input){
		char[] charArray=new char[input.length()];
		input=input.toLowerCase();
		int index=0;
		for(int i='a';i<='z';i++){
			for(int j=0;j<input.length();j++){
				if(input.charAt(j)==i)
					charArray[index++]=(char)i;
			}
		}
		return new String(charArray);
	}
}
