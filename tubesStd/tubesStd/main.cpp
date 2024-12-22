#include "graph.h"
using namespace std;

int main() {
    Graph graph;
    createGraph(graph);

    string pascalRute[] = {"Telkom University", "Bojongsoang", "Jl. Nasional 3", "Moh Toha", "Jl. Astana Anyar"};
    string tsmRute[] = {"Telkom University", "Buah Batu", "Jl. Pelajar Pejuang", "Jl. Gatot Subroto"};
    string becRute[] = {"Telkom University", "Pelajar Pejuang", "Asia Afrika", "Taman Dewi Sartika", "Jl. Wastu Kencana"};

    string rutes[][5] = {
        {"Telkom University", "Bojongsoang", "Jl. Nasional 3", "Moh Toha", "Jl. Astana Anyar"},
        {"Telkom University", "Buah Batu", "Jl. Pelajar Pejuang", "Jl. Gatot Subroto"},
        {"Telkom University", "Pelajar Pejuang", "Asia Afrika", "Taman Dewi Sartika", "Jl. Wastu Kencana"}
    };

    int ruteSizes[] = {5, 4, 5};
    string malls[] = {"Pascal", "TSM", "BEC"};
    int distances[] = {15, 12, 10};

    int pilihan;
    do {
        cout << "\n=== Menu ===\n";
        cout << "1. Tampilkan Rute ke Mall\n";
        cout << "2. Mall Terdekat\n";
        cout << "3. Mall Terdekat Hindari Wilayah\n";
        cout << "4. Keluar\n";
        cout << "Pilih menu: ";
        
        if (!(cin >> pilihan)) {
            cout << "Error: Mohon masukkan angka 1-4 saja.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        cin.ignore();

        if (pilihan < 1 || pilihan > 4) {
            cout << "Error: Pilihan menu harus antara 1-4.\n";
            continue;
        }

        switch(pilihan) {
            case 1: {
                cout << "Pilih mall (1: Pascal, 2: TSM, 3: BEC): ";
                int mallPilihan;
                
                if (!(cin >> mallPilihan)) {
                    cout << "Error: Mohon masukkan angka 1-3 saja.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }

                if (mallPilihan < 1 || mallPilihan > 3) {
                    cout << "Error: Pilihan mall harus antara 1-3.\n";
                    break;
                }

                if (mallPilihan == 1) {
                    showGraphToMall(pascalRute, 5);
                } else if (mallPilihan == 2) {
                    showGraphToMall(tsmRute, 4);
                } else if (mallPilihan == 3) {
                    showGraphToMall(becRute, 5);
                }
                break;
            }
            case 2: {
                cout << "Mall terdekat: " << findShortestMall(malls, distances, 3) << endl;
                break;
            }
            case 3: {
                string avoidArea;
                cout << "Masukkan wilayah yang ingin dihindari: ";
                getline(cin, avoidArea);
                if (avoidArea.empty()) {
                    cout << "Error: Wilayah tidak boleh kosong.\n";
                    break;
                }
                findShortestPathWithAvoid(malls, rutes, ruteSizes, 3, avoidArea);
                break;
            }
            case 4: {
                cout << "Terima kasih!\n";
                break;
            }
        }
    } while (pilihan != 4);

    return 0;
}
