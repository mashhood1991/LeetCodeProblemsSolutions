class Solution {
public:
    //ascii to integer
    int myAtoi(string s) {
        //string can have:
        //1. white spaces "42" >> 42
        //2. a +/- symbol "   - 42" >>42
        //3. numbers "2123FRGG" >>2123 
        //4. between MAX_INT and MIN_INT constarints "9999999999999" >>MAX_INT
        //5. random characters
        
        //invalid entries
        // " " >>0
        //"  +GGREG 9" >>0
        //"FFRRR" >>0
        
        int result = 0; //start with result 0, once we get character we will add them in result
        
        // first whitespace check. if white spaces then ignore
        int i =0; //index to loop through the string
        while(i<s.length() && s[i]==' ') {i++;} //also check if string is not completely empty
        
        // check +/- symbol
        int negative =1;//if you do not have anything, then number is positive
        if (i<s.length() && s[i]=='-')
        {
            i++;
            negative = -1;
        }
        else if(i<s.length() && s[i]=='+')
        {
            i++;
        }
        
        // check valid number input
        int MAX_INT = pow(2, 31) -1; //2147483647 (32 bit machine limit)
        int MIN_INT = -1*pow(2, 31); //-2147483648 (32 bit machine limit)
        while(i<s.length() && s[i]>= '0' && s[i]<='9')
        {
            //handle overflow test case
            if (result> MAX_INT/10 || (result== MAX_INT/10 && s[i] - '0' >7)) //check max, min before you increment your result
            {
                if(negative ==-1)
                    return MIN_INT;
                else
                    return MAX_INT;
            }
            result = 10 * result + (s[i++]- '0');    
            //i++; alreday i is incremented in above line after comparing due to post-increment
        }
        return result*negative;
    }
};
