template<typename V>
Edge<V>::Edge(V* vertex1, V* vertex2)
{
    this->vertex1 = vertex1;
    this->vertex2 = vertex2;
}

template<typename V>
void Edge<V>::setVertex1(V* vertex)
{
    this->vertex1 = vertex;
}

template<typename V>
void Edge<V>::setVertex2(V* vertex)
{
    this->vertex2 = vertex;
}

template<typename V>
V* Edge<V>::getVertex1()
{
    return this->vertex1;
}

template<typename V>
V* Edge<V>::getVertex2()
{
    return this->vertex2;
}

template<typename V>
string Edge<V>::toString()
{
    return this->vertex1->toString() + '-' + this->vertex2->toString();
}

template<typename V>
bool Edge<V>::hasVertices(int vertexNum1, int vertexNum2)
{
    return (
        (this->vertex1->getNumber() == vertexNum1 && this->vertex2->getNumber() == vertexNum2) ||
        (this->vertex1->getNumber() == vertexNum2 && this->vertex2->getNumber() == vertexNum1)
    );
}

template<typename V>
bool Edge<V>::bothVerticesSameState()
{
    return this->vertex1->isOpen() == this->vertex2->isOpen();
}

template<typename V>
bool Edge<V>::isVisited()
{
    return this->visited;
}

template<typename V>
void Edge<V>::visit()
{
    this->visited = true;
}

template<typename V>
void Edge<V>::unvisit()
{
    this->visited = false;
}

template<typename V>
V* Edge<V>::getOpenVertex()
{
    // assumes one vertex is closed, second one open
    // returns the open vertex
    if(this->vertex1->isOpen() == this->vertex2->isOpen())
    {
        cout << "Both vertices in the same state. open: " << to_string(this->vertex1->isOpen()) << endl;
        return NULL;
    }
    if(this->vertex1->isOpen())
    {
        return this->vertex1;
    } else {
        return this->vertex2;
    }
}

template<typename V>
V* Edge<V>::getClosedVertex()
{
    // assumes one vertex is closed, second one open
    // returns the open vertex
    if(this->vertex1->isOpen() == this->vertex2->isOpen())
    {
        cout << "Both vertices in the same state. open: " << to_string(this->vertex1->isOpen()) << endl;
        return NULL;
    }
    if(this->vertex1->isOpen())
    {
        return this->vertex2;
    } else {
        return this->vertex1;
    }
}

template<typename V>
V* Edge<V>::getOtherVertex(int vertexNum)
{
    // returns the other vertex than the one specified by vertexNum
    if(this->vertex1->getNumber() == vertexNum)
    {
        return this->vertex2;
    } else {
        return this->vertex1;
    }
}