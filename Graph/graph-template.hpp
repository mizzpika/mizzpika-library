//graph_template
struct Edge{
    long long to;
    long long cost;
    Edge(long long to, long long cost) : to(to), cost(cost) {}
    bool operator>(const Edge &e) const{
        return cost > e.cost;
    }
    bool operator<(const Edge &e) const{
        return cost < e.cost;
    }
};

struct Edge2{
    long long from;
    long long to;
    long long cost;
    Edge2(long long from, long long to, long long cost) : from(from), to(to), cost(cost) {}
    bool operator>(const Edge2 &e) const{
        return cost > e.cost;
    }
    bool operator<(const Edge2 &e) const{
        return cost < e.cost;
    }
};

struct Edge3 {
    long long to;
    Edge3(long long to) : to(to) {}
};

struct Graph{
    Graph() = default;
    vector<vector<Edge>> G;

    Graph(long long N){
        G.resize(N);
    }

    long long size(){
        return G.size();
    }

    void add(long long from, long long to, long long cost = 1){
        G[from].push_back(Edge(to, cost));
        G[to].push_back(Edge(from, cost));
    }

    void add_di(long long from, long long to, long long cost = 1){
        G[from].push_back(Edge(to, cost));
    }

    vector<Edge> &operator[](long long v){
        return G[v];
    }
};
