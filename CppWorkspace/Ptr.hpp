#ifndef PTR_HPP
#define PTR_HPP

template<class T>
class Ptr
{
public:
	T* m_pObject;
	int* m_pCounter;

	Ptr()
	{
		m_pCounter = NULL;
		m_pObject = NULL;
	}

	Ptr(T* object) 
	{
		m_pObject = object;
		m_pCounter = new int;
		*m_pCounter = 1;
	}

	Ptr(const Ptr<T>& rhs)
	{
		this->operator=(rhs);
	}

	Ptr& operator=(const Ptr<T>& rhs)
	{
		if (this == &rhs) return *this;

		if (m_pObject == NULL && rhs.m_pObject != NULL)
		{
			m_pObject = rhs.m_pObject;
			m_pCounter = rhs.m_pCounter;
			(*m_pCounter)++;
		}
		if (rhs.m_pObject == NULL && m_pObject != NULL)
		{
			(*m_pCounter)--;
			if (*m_pCounter == 0)
			{
				delete m_pCounter;
				delete m_pObject;
			}
			m_pObject = NULL;
			m_pCounter = NULL;
		}
		if (m_pObject != NULL && rhs.m_pObject != NULL)
		{
			(*m_pCounter)--;
			if (*m_pCounter == 0)
			{
				delete m_pCounter;
				delete m_pObject;
			}
			m_pObject = rhs.m_pObject;
			m_pCounter = rhs.m_pCounter;
			(*m_pCounter)++;
		}

		return *this;
	}

	~Ptr()
	{
		if (!m_pObject) return;
		(*m_pCounter)--;
		printf("%d\n", *m_pCounter);
		system("pause");
		if (*m_pCounter == 0)
		{
			delete m_pCounter;
			delete m_pObject;
		}
	}


};

#endif
