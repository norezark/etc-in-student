class PrintEachChar
{
    public static void main(String[] args)
    {
        String mike = "この猫の名前はMikeです";
        for(int i = 0; i < mike.length(); i++)
        {
            System.out.println(i + " : " + mike.charAt(i));
        }
    }
}
