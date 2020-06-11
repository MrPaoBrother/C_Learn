#ifndef ARRAY_H_
#define ARRAY_H_

template<class Type, int n>
class ArrayTP{
private:
    Type items[n];
public:
    ArrayTP();
    explicit ArrayTP(const ArrayTP &);

    virtual Type operator[](int i);
    virtual Type & operator[](int i) const;
};
template<class Type, int n>
ArrayTP<Type, n>::ArrayTP(){

}

template<class Type, int n>
ArrayTP<Type, n>::ArrayTP(const ArrayTP & arrTP){
    for(int i=0;i<n;i++){
        items[i] = arrTP.items[i];
    }
}


template<class Type, int n>
Type ArrayTP<Type, n>::operator[](int i){
    return items[i];
}

template<class Type, int n>
Type & ArrayTP<Type, n>::operator[](int i) const{
    return items[i];
}
#endif