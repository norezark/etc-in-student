class NengoUtil
{
    int getYearFromNengo(char NengoChar, int NengoYear)
    {
        if(NengoChar == 'S')
        {
            if(NengoYear >= 1 && NengoYear <= 64)
            {
                return 1925 + NengoYear;
            }
            else return -1;
        }
        else if(NengoChar == 'H')
        {
            if(NengoYear >= 1 && NengoYear <= 31)
            {
                return 1988 + NengoYear;
            }
            else return -1;
        }

        return -1;
    }
}
