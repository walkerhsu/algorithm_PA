# include <iostream>
# include <fstream>
using namespace std;

void ReadFile(vector<int> &data, char *path);

int main(int argc, char *argv[])
{
    assert(argc == 3);
    vector<int> data1;
    vector<int> data2;
    ReadFile(data1, argv[1]);
    ReadFile(data2, argv[2]);
    assert(data1.size() == data2.size());
    for (int i = 0; i < data1.size(); i++) {
        assert(data1[i] == data2[i]);
    }
    cout << "Two sorting methods have the same output ~~~"<<endl;
}

void ReadFile(vector<int>& data, char* path) {
    char buffer[200];
    fstream file(path);
    file.getline(buffer, 200);
    int junk,num;
    while (file >> junk >> num)
        data.push_back(num);
}