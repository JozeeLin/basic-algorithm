class Solution {
public:
    void push(int value) {
        if(m_min.empty())
            m_min.push(value);
        else if(value<m_min.top())
            m_min.push(value);
        else{
            int min = m_min.top();
            m_min.push(min);
        }
        m_data.push(value);
             
    }
    void pop() {
        m_min.pop();
        m_data.pop();
    }
    int top() {
        return m_data.top();
    }
    int min() {
        return m_min.top();
    }
private:
    std::stack<int>m_min;
    std::stack<int>m_data;
};
