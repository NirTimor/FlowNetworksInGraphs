#include "Global.h"
Edge* getData(int& NumofVertices, int& NumofEdges, int& s, int& t) {
	string line, temp;
    Edge e;
    int i, j;
    int count = 0;
    int cutFrom = 0;
    int lineSize = 0;
    int validC;
    int c = 0;
    getline(cin,line);
    NumofVertices = stoi(line);
    if (NumofVertices < 1) {
        cout << "Invalid Input!";
            exit(1);
    }
    getline(cin, line);
    NumofEdges = stoi(line);
    if (NumofEdges < 0) {
        cout << "Invalid Input!";
        exit(1);
    }
    getline(cin, line);
    s = stoi(line);
    if (s < 1 || s > NumofVertices) {
        cout << "Invalid Input";
        exit(1);
    }
    getline(cin, line);
    t = stoi(line);
    if (t < 1 || t > NumofVertices) {
        cout << "Invalid Input";
        exit(1);
    }
    Edge* EdgesArr = new Edge[NumofEdges*2]; // in case we need for every edge the Anti-Parallel of her
    for (i = 0; i < NumofEdges; i++) {
        getline(cin, line);
        lineSize = line.size();
        c = line[0];
        for (j = 0; j < 3; j++) {
            while ((c != ' ') && (c != '\0')) {
                count++;
                c = line[count];
            }
            temp = line.substr(cutFrom, count);
            cutFrom = count;
            if (j == 0) {
                e.setEdgeU(stoi(temp));
            }
            else if (j == 1) {
                e.setEdgeV(stoi(temp));
            }
            else if (j == 2) {
                validC = stoi(temp);
                if (validC < 0) {
                    cout << "Invalid Input!" << endl;
                    exit(1);
                }
                e.setEdgeCapacity(stoi(temp));
            }
            if (count != lineSize) {
                count++;
            }
            if (count == lineSize && j < 2) {
                cout << "Invalid Input!" << endl;
                exit(1);
            }
            c = line[count];
        }
        EdgesArr[i].setEdgeU(e.getEdgeU());
        EdgesArr[i].setEdgeV(e.getEdgeV());
        EdgesArr[i].setEdgeCapacity(e.getEdgeCapacity());
        count = 0;
        cutFrom = 0;
    } 
    for (int i = 0; i < NumofEdges; i++) {
        if ((EdgesArr[i].getEdgeU() > NumofVertices) || (EdgesArr[i].getEdgeU() < 1) || (EdgesArr[i].getEdgeV() > NumofVertices) || (EdgesArr[i].getEdgeV() < 1))
        {
            cout << "Invalid Input!" << endl;
            exit(1);
        }
    }
     return EdgesArr;
 }
void MarkEdgesWithoutParallelEdge(Edge* EdgesArr, int NumofVerticals, int NumofEdges) {
    for (int i = 0; i < NumofEdges - 1; i++) {
        if ((EdgesArr[i].getEdgeU() == EdgesArr[i + 1].getEdgeV()) && (EdgesArr[i].getEdgeV() == EdgesArr[i + 1].getEdgeU())) {
            EdgesArr[i].setisNegativeEdgeExist(true);
            EdgesArr[i + 1].setisNegativeEdgeExist(true);
        }
    }
    if ((EdgesArr[NumofEdges - 1].getEdgeU() == EdgesArr[NumofEdges].getEdgeV()) && (EdgesArr[NumofEdges - 1].getEdgeV() == EdgesArr[NumofEdges].getEdgeU()))
    {
        EdgesArr[NumofEdges - 1].setisNegativeEdgeExist(true);

    }
}
int CorrectingEdgesArr(Edge* EdgesArr, int NumofVerticals, int NumofEdges) { // check if anti parallel is true then dont do anything else insert the anti paralell with capacity 0 and flow to be -flow of anti parallel edge
    int j = NumofEdges;
    for (int i = 0; i < j; i++)  {
        if (EdgesArr[i].getisNegativeEdgeExist() == true) {
            continue;
        }
        else {
            EdgesArr[NumofEdges].setEdgeU(EdgesArr[i].getEdgeV());
            EdgesArr[NumofEdges].setEdgeV(EdgesArr[i].getEdgeU());
            EdgesArr[NumofEdges].setEdgeCapacity(0);
            EdgesArr[NumofEdges].setEdgeFlow(0);
            NumofEdges++;
        }
    }
    int FinalNumofEdges = NumofEdges;
    return FinalNumofEdges;
}