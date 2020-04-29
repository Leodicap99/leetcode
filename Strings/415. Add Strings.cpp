/*
I would suggest u to use this method as it will help u int the question (2. Add two numbers) which is a must do interview question.
How we are going to do this is that we will reverse the strings and will propagate carry from left to right as this would be easy to implement.

num1 = "23"
num2 = "37"

after reversing 
num1 = "32"
num2 = "73"

we add 3 and 10 and mod it with 10 and propagate (sum/10) to the right so here (7+3)%10 and propaget 1(10/10) to the left
*/
    string addStrings(string num1, string num2) {
      if(num1.size()==0&&num2.size()==0)return "";
      if(num1.size()==0)return num2;
        if(num2.size()==0)return num1;
      reverse(num1.begin(),num1.end());
      reverse(num2.begin(),num2.end());
        string ans;
        int i=0,carry=0;
        while(i<num1.size()||i<num2.size())
        {
            int sum=carry;
            if(i<num1.size())
                sum+=num1[i]-'0';
            if(i<num2.size())
                sum+=num2[i]-'0';
            ans+=to_string(sum%10);
            carry=sum/10;
            i++;
        }
        if(carry)ans+=to_string(carry);
        reverse(ans.begin(),ans.end());
        return ans;
    }