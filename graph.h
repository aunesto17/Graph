//
//  Header.h
//  Graphs
//
//  Created by Alexander Arturo Baylon Ibanez on 13/12/15.
//  Copyright © 2015 aunesto17. All rights reserved.
//

#ifndef Header_h
#define Header_h

#include <stdio.h>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <list>


using namespace std;


template<class G>
class cNode
{
public:
    typedef typename G::No   N;
    typedef typename G::Edge Edge;
    N m_data;
    vector<Edge*> m_edges;
    //metodos
    cNode(N x){
        m_data = x;
    }
    ~cNode(){};
};


template<class G>
class cEdge
{
    typedef typename G::Node Node;
    typedef typename G::Ej    E;
    E m_data;       //data
    Node * m_node[2];//nodos
    bool m_dir;     //direccion
    
    //constructor
    cEdge(Node * a,Node * b,E e,bool d){
        m_node[0] = a;
        m_node[1] = b;
        m_data    = e;
        m_dir     = d;
    }
    ~cEdge(){};
};


template<class N, class E>
class cGraph
{
public:
    typedef cGraph<N,E> self;
    typedef cNode<self> Node;
    typedef cEdge<self> Edge;
    typedef N No;
    typedef E Ej;
    vector<Node *> m_nodes;
    
    //metodos
    bool insertNode(N x);
    bool insertEdge(Node *,Node *,bool,E);
    bool removeEdge(Node *,Node *,E );
    bool removeNode(N x);
    void removeEdgefromNode(Node *,E);
    ~cGraph(){};
};



template<class N,class E>
bool cGraph<N,E>::insertNode(N x)
{
    Node * t = new Node(x);
    m_nodes.push_back(t);
    return 1;
}


template<class N,class E>
bool cGraph<N,E>::insertEdge(Node * a, Node * b, bool dir,E e)
{
    Edge * newEdge = new Edge(a,b,e,dir);
    a->m_edges.push_back(newEdge);
    b->m_edges.push_back(newEdge);
}


template<class N,class E>
bool cGraph<N,E>::removeEdge(Node * a, Node * b, E e)
{
    typename vector<Edge*>::iterator i;
    typename vector<Edge*>::iterator f=a->m_edges.end();
    Edge * t;
    
    for (i = a->m_edges.begin(); i!=f; i++) {
        if (i->m_node[0]==a && i->m_data==e) {
            t = (*i);
            a->m_edges.erase(i);
        }
    }
    
    f=a->_edges.end();
    for (i = b->m_edges.begin(); i!=f; i++) {
        if (i->m_node[1]==b && i->m_data==e) {
            b->m_edges.erase(i);
        }
    }
    //borramos la arista
    delete t;
    
}

template<class N,class E>
bool cGraph<N,E>::removeNode(N x)
{
    typename vector<Node *>::iterador i;
    Node * t;
    for (int i=0; i<m_nodes.size(); i++) {
        if (m_nodes[i]->m_data == x) {
            t = m_nodes[i];
            m_nodes.erase(m_nodes.begin()+i);
            break;
        }
    }
    //borramos el nodo
    delete t;
}

#endif /* Header_h */
