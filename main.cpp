//
//  main.cpp
//  tree_0.0.1
//
//  Created by Сурков Дмитрий Валерьевич on 15.04.2018.
//  Copyright © 2018 Сурков Дмитрий Валерьевич. All rights reserved.
//

#include <iostream>


class tree_t
{
private:
    struct node_t
    {
        node_t * left;
        node_t * right;
        int key;
        
        node_t()
        {
            left = nullptr;
            right = nullptr;
            key = 0;
        }
        
        ~node_t()
        {
            delete left;
            delete right;
        }
        
        void addingkey(int value)
        {
            if (key > value)
            {
                if (left == nullptr)
                {
                    left = new node_t();
                    left->key = value;
                }  
                else left->addingkey(value);
            }
            else if (right == nullptr)
            {
                right = new node_t();
                right->key = value;
            }
            else right->addingkey(value);
            return;
        }
        
        bool findingkey(int value)
        {
            if (key == value)
            {
                return true;
            }
            if (key > value)
            {
                if (left != nullptr)
                {
                    return left->findingkey(value);
                }
                else return false;
            }
            if (key < value)
            {
                if (right != nullptr)
                {
                    return right->findingkey(value);
                }
                else return false;
            }
        }
        
        void print_tree(std::ostream & stream, int line = 0)
        {
            if (left != nullptr)
            {
                left->print_tree(stream, line + 4);
            }
            for (int i = 0; i < line + 4; i ++)
                stream << '-';
            stream << key << std::endl;
            if (right)
            {
                right-> print_tree(stream, line +4);
            }
        }
    };
    
private:
    node_t * root_;
public:
    void insert(int key)
    {
        if (root_ == nullptr)
        {
            root_ = new node_t;
            root_->key = key;
            return;
        }
        else
        {
            root_->addingelem(key);
            return;
        }
    }
    bool find(int key) const
    {
        if (root_ != nullptr)
        {
            root_->findingelem(key);
        }
        return false;
    }
    
    void print(std::ostream & stream) const
    {
        if (root_ != nullptr)
        {
            root_->print_tree(stream, 0);
        }
        else std::cout << "ERROR! Tree is empty!" << std::endl;
        return;
    }
};





int main()
{
    tree_t tree;
    char op;
    while (std::cin >> op && op != 'q')
    {
        int a;
        switch (op)
        {
            case '=':
                tree.print(std::cout);
                break;
            case '?':
                if (std::cin >> a)
                {
                    if (!tree.find(a))
                    {
                        std::cout << "Element is in tree";
                    }
                    else std::cout << "Element isn't in tree";
                }
                else
                {
                    std::cout << "An error has occured while reading input data" << std::endl;
                    exit(0);
                }
                break;
            case '+':
                if (std::cin >> a)
                {
                    tree.insert(a);
                    tree.print(std::cout);
                }
                else
                {
                    std::cout << "An error has occured while reading input data" << std::endl;
                    exit(0);
                }
                break;
        }
        return 0;
    }
}
