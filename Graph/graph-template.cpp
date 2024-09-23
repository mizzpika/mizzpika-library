//graph_template
struct Edge{
    ll to;
    ll cost;
    Edge(ll to, ll cost) : to(to), cost(cost) {}
    bool operator>(const Edge &e) const{
        return cost > e.cost;
    }
    bool operator<(const Edge &e) const{
        return cost < e.cost;
    }
};

struct Edge2{
    ll from;
    ll to;
    ll cost;
    Edge2(ll from, ll to, ll cost) : from(from), to(to), cost(cost) {}
    bool operator>(const Edge2 &e) const{
        return cost > e.cost;
    }
    bool operator<(const Edge2 &e) const{
        return cost < e.cost;
    }
};

struct Edge3 {
    ll to;
    Edge3(ll to) : to(to) {}
};

struct Graph{
    Graph() = default;
    vector<vector<Edge>> G;

    Graph(ll N){
        G.resize(N);
    }

    ll size(){
        return G.size();
    }

    void add(ll from, ll to, ll cost = 1){
        G[from].push_back(Edge(to, cost));
        G[to].push_back(Edge(from, cost));
    }

    void add_di(ll from, ll to, ll cost = 1){
        G[from].push_back(Edge(to, cost));
    }

    vector<Edge> &operator[](ll v){
        return G[v];
    }
};
