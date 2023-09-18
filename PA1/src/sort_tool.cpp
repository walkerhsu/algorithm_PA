// **************************************************************************
//  File       [sort_tool.cpp]
//  Author     [Yu-Hao Ho]
//  Synopsis   [The implementation of the SortTool Class]
//  Modify     [2020/9/15 Mu-Ting Wu]
//  Modify     [2023/9/12 Ming-Bang Fan]
// **************************************************************************

#include "sort_tool.h"
#include <iostream>
#define ll long long
#define BIGNUMBER 2147483647 
// Constructor
SortTool::SortTool() {}

// Insertion sort method
void SortTool::InsertionSort(vector<int>& data) {
    // Function : Insertion sort
    // TODO : Please complete insertion sort code here
    for (int i = 1; i < data.size(); i++)
    {
        int cur_idx = i-1;
        int cur_value = data[i];
        while (cur_idx >= 0)
        {
            if(cur_value >= data[cur_idx])
                break;
            data[cur_idx + 1] = data[cur_idx];
            cur_idx -= 1;
        }
        data[cur_idx + 1] = cur_value;
    }
}

// Quick sort method
void SortTool::QuickSort(vector<int>& data, int f){
    QuickSortSubVector(data, 0, data.size() - 1, f);
}
// Sort subvector (Quick sort)
void SortTool::QuickSortSubVector(vector<int>& data, int low, int high, const int flag) {
    // Function : Quick sort subvector
    // TODO : Please complete QuickSortSubVector code here
    // Hint : recursively call itself
    //        Partition function is needed
    // flag == 0 -> normal QS
    // flag == 1 -> randomized QS
}
int SortTool::RandomizedPartition(vector<int>& data, int low, int high){
    // Function : RQS's Partition the vector 
    // TODO : Please complete the function
}

int SortTool::Partition(vector<int>& data, int low, int high) {
    // Function : Partition the vector 
    // TODO : Please complete the function
}

// Merge sort method
void SortTool::MergeSort(vector<int>& data){
    MergeSortSubVector(data, 0, data.size() - 1);
}

// Sort subvector (Merge sort)
void SortTool::MergeSortSubVector(vector<int>& data, int low, int high) {
    // Function : Merge sort subvector
    // TODO : Please complete MergeSortSubVector code here
    // Hint : recursively call itself
    //        Merge function is needed
    if (low == high)
        return;
    MergeSortSubVector(data, low, (low + high) / 2);
    MergeSortSubVector(data, ((low + high) / 2) + 1, high);
    Merge(data, low, (low + high) / 2, ((low + high) / 2) + 1, high);
}

// Merge
void SortTool::Merge(vector<int>& data, int low, int middle1, int middle2, int high) {
    // Function : Merge two sorted subvector
    // TODO : Please complete the function
    vector<int> front_data;
    vector<int> back_data;
    if (low == middle1) front_data.push_back(data[low]);
    else {
        for (int i = low; i <= middle1; i++) {
            front_data.push_back(data[i]);
        }
    }
    if (middle2 == high) back_data.push_back(data[high]);
    else {
        for (int i = middle2; i <= high; i++)
        {
            back_data.push_back(data[i]);
        }
    }
    front_data.push_back(BIGNUMBER);
    back_data.push_back(BIGNUMBER);

    int front_idx = 0;
    int back_idx = 0;
    for (int i = low; i <= high; i++)
    {
        if(front_data[front_idx] < back_data[back_idx]) {
            data[i] = front_data[front_idx];
            front_idx += 1;
        }
        else{
            data[i] = back_data[back_idx];
            back_idx += 1;
        }
    }
    // PrintData(data, low, high);
}

// Heap sort method
void SortTool::HeapSort(vector<int>& data) {
    // Build Max-Heap
    BuildMaxHeap(data);
    // 1. Swap data[0] which is max value and data[i] so that the max value will be in correct location
    // 2. Do max-heapify for data[0]
    for (int i = data.size() - 1; i >= 1; i--) {
        swap(data[0],data[i]);
        heapSize--;
        MaxHeapify(data,0);
    }
}

//Max heapify
void SortTool::MaxHeapify(vector<int>& data, int root) {
    // Function : Make tree with given root be a max-heap if both right and left sub-tree are max-heap
    // TODO : Please complete max-heapify code here
}

//Build max heap
void SortTool::BuildMaxHeap(vector<int>& data) {
    heapSize = data.size(); // initialize heap size
    // Function : Make input data become a max-heap
    // TODO : Please complete BuildMaxHeap code here
}

void SortTool::PrintData(vector<int> data, int low, int high) {
    for (int i = low; i <= high; i++) {
        std::cout << data[i] << ' ';
    }
    std::cout << endl;
}