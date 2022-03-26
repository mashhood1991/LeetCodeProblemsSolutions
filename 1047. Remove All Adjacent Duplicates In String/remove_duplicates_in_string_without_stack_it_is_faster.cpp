class Solution {
public:
    string removeDuplicates(string s) {
/*        
//stack is very helpful in problems where you have to remove some part out and the then the remaining parts you have to concatenate
//stack is LIFO data structure
        

The functions associated with stack are: 
empty() – Returns whether the stack is empty – Time Complexity : O(1) 
size() – Returns the size of the stack – Time Complexity : O(1) 
top() – Returns a reference to the top most element of the stack – Time Complexity : O(1) 
push(g) – Adds the element ‘g’ at the top of the stack – Time Complexity : O(1) 
pop() – Deletes the top most element of the stack – Time Complexity : O(1) 

//here what we will do is, we first push the first charcter into the stack, and then check it with the second character, if it matches then do not put the charcter inside the stack as well as pop_out the previous charcter (LIFO helps)
//create string builder and finally reverese the string and return it

//first solution: using stack and simple for loop 
        //stack ds to store the ch
        stack<char> st;
        
        for(int i=0; i<s.size(); i++)
        {
            if(st.size()>0 && st.top()==s[i])
                st.pop();
            else
                st.push(s[i]);
        }
        
        //define an empty string to store the stack results into string
        string ans="";
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin() , ans.end());
        return ans;
        
//second solution: using range based for loop      
        //stack ds to store the ch
        stack<char> st;
        
        for(char& c : s) //here c is referencing to s
        {
            if(st.size()>0 && st.top()==c)
                st.pop();
            else
                st.push(c);
        }
        
        //define an empty string to store the stack results into string
        string ans="";
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin() , ans.end());
        return ans;
*/
       
//third solution: without using stack, seems bit faster
        string ans{}; //empty string to store the result
        
        for(char &c : s){
            if(ans.empty())
                ans.push_back(c);
            else{
                if(ans.back() == c) //front return first character and back returns last character of a string
                    ans.pop_back();
                else
                    ans.push_back(c);
            }
        }
        
        return ans;  
    }
};
