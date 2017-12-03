#include <iostream>

using namespace std;

int distance_tabel[1000][1000];
int next_hop_tabel[1000][1000];
int n_node ;
long int edge ;
int pre_hop;
int dest_hop;
int pre ;
int dest ;
int y ;

void initiate_tabel(int n_node) {
    for (int i = 0; i < n_node ; ++i) {
        for (int j = 0; j < n_node ; ++j) {
            if (j == i) {
                distance_tabel[i][j] = 0;
                next_hop_tabel[i][j] = j + 1;
            } else {
                distance_tabel[i][j] = -1;
                next_hop_tabel[i][j] = -1;
            }
        }
    }
}

void connect_node(int edge) {
    for (int n = 0; n < edge; ++n) {
        cin >> pre_hop >> dest_hop ;
        if ((dest_hop-1 != pre_hop-1) && (dest_hop-1 >= 0 && dest_hop-1 < n_node) && (pre_hop-1 >= 0 && pre_hop-1 < n_node)) {
            distance_tabel[pre_hop-1][dest_hop-1] = 1 ;
            next_hop_tabel[pre_hop-1][dest_hop-1] = dest_hop ;
            distance_tabel[dest_hop-1][pre_hop-1] = 1 ;
            next_hop_tabel[dest_hop-1][pre_hop-1] = pre_hop ;
        }
    }
}

void update_tabel(int y) {
    for (int m = 0; m < y; ++m) {
        cin >> pre >> dest ;
        for (int index = 0; index < n_node; ++index) {
            if (index != pre-1 && index != dest-1 && distance_tabel[pre-1][index] != -1) {
                if((distance_tabel[dest-1][index] == -1) ||  (distance_tabel[pre-1][index] + 1) < distance_tabel[dest-1][index]) {
                    distance_tabel[dest-1][index] = distance_tabel[pre-1][index] + 1;
                    next_hop_tabel[dest-1][index] = pre;
                } else if((distance_tabel[pre-1][index] + 1) == distance_tabel[dest-1][index] && next_hop_tabel[dest-1][index] > pre) {
                    next_hop_tabel[dest-1][index] = pre;
                } 
            }
        }

    }
}

void print_node(int n_node) {
    for (int i = 0; i < n_node; ++i) {
        for (int j = 0; j < n_node; ++j) {
            cout << distance_tabel[i][j]<<" "<<next_hop_tabel[i][j] << endl;
        }
    }
}

int main() {
    cin >> n_node >> edge ;

    initiate_tabel(n_node);
    connect_node(edge);
   
    cin >> y;
    update_tabel(y);
    print_node(n_node);

    

    return 0;
}
