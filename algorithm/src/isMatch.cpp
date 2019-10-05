////
//// Created by cxl on 19-9-24.
////
//#include <iostream>
//using namespace std;
//
//bool isMatch(const char *s, const char *p){
//    if(*p=='*'){
//        while(*p=='*'){
//            p++;//跳出连续的*
//            if (*p=='\0'){
//                return true;
//            }
//            while(*s!='\0'&&!isMatch(s,p)){
//                s++;
//            }
//            if (*s=='\0'){
//                return false;
//            }
//            else{
//                return true;
//            }
//        }
//    }
//    else if (*p=='\0'||*s=='\0'){
//        return (*p==*s);
//    }
//    else if (*p==*s ||*p=='?'){
//        return isMatch(++s,++p);
//    }
//    else{
//        return false;
//    }
//}
//int main(){
//    cout<<isMatch("aa","a")<<endl;
//    cout<<isMatch("aa","aa")<<endl;
//    cout<<isMatch("aaa","aa")<<endl;
//    cout<<isMatch("aa","*")<<endl;
//    cout<<isMatch("ab","?")<<endl;
//    cout<<isMatch("aa","a*")<<endl;
//    cout<<isMatch("aab","c*a*b")<<endl;
//}