#include <iostream>
#include <vector>

using namespace std;

template <typename T, typename U>
class Addition{
    T data1;
    U data2;
    public :
    Addition(T val1, U val2) : data1(val1), data2(val2) {}
    void displaySum() {
        cout << "Sum: " << (data1 + data2) << '\n';
    }
};

// Template specialization for string and whatever type
template <typename U>
class Addition<string, U>{
    string data1;
    U data2;
    public :
    Addition(string val1, U val2) : data1(val1), data2(val2) {}
    void displaySum() {
        cout << "Concatenated Result: " << (data1 + " "+ to_string(data2)) << '\n';
    }
};

//Template specialization for whatever type and string
template<typename T>
class Addition<T, string>
{
  public:
    T data1;
    string data2;
    Addition(T val1, string val2) : data1(val1), data2(val2){}
    void displaySum()
    {
        cout << "Concatenated Result: " << (to_string(data1) + " " + data2) << '\n';
    }

};

//Template specialization for whatever type and string
template<>
class Addition<string, string>
{
  public:
    string data1;
    string data2;
    Addition(string val1, string val2) : data1(val1), data2(val2){}
    void displaySum()
    {
        cout << "Concatenated Result: " << data1 + " " + data2 << '\n';
    }

};

// template specialization for vector types
template <typename T>
class Addition<vector<T>, vector<T>>
{ 
    public:
    vector<T> data1;
    vector<T> data2;
    Addition(vector<T> val1, vector<T> val2) : data1(val1), data2(val2) {}
    void displaySum() {
        vector<T> result;
        size_t total_size = data1.size() + data2.size();
        result.reserve(total_size);
        result.insert(result.end(), data1.begin(), data1.end());
        result.insert(result.end(), data2.begin(), data2.end());
        cout << "Vector addition: ";
        for (const auto& val : result) {
            cout << val << " ";
        }
        cout << '\n';
    }
};


int main()
{
    cout << "This file demonstrates template specialization in C++.\n";
    Addition<bool, int> addObj1(true, 5);
    addObj1.displaySum();

    Addition<string, string> addObj2("Hello", " World");
    addObj2.displaySum();

    Addition<string, int> addObj3("Hello", 20);
    addObj3.displaySum();
    Addition<float, string> addObj4(3.14f, "Pi Value");
    addObj4.displaySum();

    vector<float> vec1 = {1.1f, 2.2f, 3.3f};
    vector<float> vec2 = {4.4f, 5.5f};

    Addition<vector<float>, vector<float>> addObj5(vec1, vec2);
    addObj5.displaySum();
    return 0;
}