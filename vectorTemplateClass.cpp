template<typename T>
class Vector{
    T *arr;
    int cs;
    int ms;
public:
    Vector(int s=4){
        arr=new T[s];
        cs=0;
        ms=s;
    }
    void push_back(const T d){
        if(cs==ms){
            //expand the vector if full
            T*oldArr=arr;
            int oldSize=ms;
            ms=ms<<1;
            arr=new T[ms];
            for(int i=0;i<cs;i++){
                arr[i]=oldArr[i];
            }
            delete [] oldArr;
            oldArr=NULL;
        }
        arr[cs]=d;
        cs++;
    }
    void pop_back(){
        if(cs>0){
            cs--;
        }
    }
    int size() const{
        return cs;
    }
    int capacity() const{
        return ms;
    }
    T operator[] (int i){
        return arr[i];
    } 
};