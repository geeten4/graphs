using namespace std;

template<typename V>
WeightedEdge<V>::WeightedEdge(V* vertex1, V* vertex2, float weight) : Edge<V>(vertex1, vertex2)
{
    this->weight = weight;
}

template<typename V>
string WeightedEdge<V>::toString()
{
    return this->vertex1->toString() + "-(" + to_string(this->weight) + ")-" + this->vertex2->toString();
}

template<typename V>
float WeightedEdge<V>::getWeight()
{
    return this->weight;
}

template<typename V>
bool operator==(const WeightedEdge<V> &lhs, const WeightedEdge<V> &rhs)
{
    return lhs.weight == rhs.weight;
}

template<typename V>
bool operator<(const WeightedEdge<V> &lhs, const WeightedEdge<V> &rhs)
{
    return lhs.weight < rhs.weight;
}

template<typename V>
bool operator>(const WeightedEdge<V> &lhs, const WeightedEdge<V> &rhs)
{
    return lhs.weight > rhs.weight;
}
