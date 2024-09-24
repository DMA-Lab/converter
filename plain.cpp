
#include <fstream>
#include <sstream>
#include <string>
#include <format>
#include <climits>
#include <cstring>
#include <iostream>
#include "plain.h"
#include "graph.h"


Graph load_plain(const std::string &path) {
    Graph g;
    ifstream file;

    file.open(path, std::ios::in);
    if (!file) {
        throw std::runtime_error(std::format("can't open file {}: {}\n", path, std::strerror(errno)));
    }

    for (string line; std::getline(file, line);) {
        stringstream ss(line);

        char operation;
        ss >> operation;

        switch (operation) {
        case'a': {
            Vertex start, end;
            EdgeWeight weight;
            ss >> start >> end >> weight;
            /* 由于 limit 的存在，我们可能只能加载部分图，尽可能地希望恰好加载 limit 个顶点.
             * 约束：可以缺少一个，但不能多出一个. */
            g.add_directional_edge(start, end, weight);
            break;
        }
        case'p': {
            unsigned int edge_count, vertex_count;
            string sp;
            ss >> sp >> vertex_count >> edge_count;
            for (int i = 0; i < vertex_count; i++) {
                g.insert_vertex(i);
            }
            break;
        }
        case 'c': {
            //auto声明变量是自动类型，注意：使用auto必须要进行初始化！
            auto comment = line.substr(0);
            cout << comment << endl;
            break;
        }
        default: {
            cerr << "unknown operation: " << operation << endl;
            break;
            }
        }
    }
    return g;
}

