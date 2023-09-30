import axios from 'axios';
import React, { useEffect, useState } from 'react'

type Props = {}



export default function HistoryDashboard({ }: Props) {

  const [histories, setHistories] = useState([]);

  const [text, setText] = useState('');

  const [errors, setErrors] = useState([]);


  useEffect(() => {
    axios.get('/api/history-receive').then((response) => {
      setHistories(response.data)
    })
  }, []);

  const handleEdit = (histories) => {
    const formData = new FormData();
    formData.append('id', histories.id);
    formData.append('text', histories.history_text);

    axios.post('/api/history-edit', formData)
      .then(responce => {
        if (responce.data.success) {
          axios.get('/api/history-receive').then((response) => {
            setHistories(response.data)
          })
        }
      })
  };

  const handleDelete = async (histories) => {
    await axios.post('/api/history-delete', histories);
    axios.get('/api/history-receive').then((response) => {
      setHistories(response.data)
    })
  };

  const handleTextChange = (id, event) => {
    const newHistories = histories.map((h) => {
      if (h.id === id) {
        return { ...h, history_text: event.target.value };
      } else {
        return h;
      }
    });
    setHistories(newHistories);
  };

  const handleSubmit = async (event: React.FormEvent<HTMLFormElement>) => {
    event.preventDefault();
    const formData = new FormData();
    formData.append('history_text', text);

    try {
      const response = await axios.post('/api/history-store', formData);
      if (response.data.success) {
        axios.get('/api/history-receive').then((response) => {
          setHistories(response.data);
        })
      }
    } catch (error) {
      console.log(error.response.data.errors);
    }

  }
  return (

    <>
      <div className='min-h-screen bg-gradient-to-b from-slate-200 from-50% to-emerald-200'>
        <div className='flex-wrap flex justify-center' >
          {histories.length ?
            (histories.map((n) => (

              <div key={n.id} className='w-1/5 flex m-5 bg-white flex-col  rounded-lg shadow p-6'>
                <textarea className="text-gray-700 leading-relaxed" value={n.history_text} onChange={(event) => handleTextChange(n.id, event)} />
                <div className='flex flex-row justify-between'>
                  <button onClick={() => handleEdit(n)}
                    className='p-2 rounded shadow-md bg-blue-600 text-white m-2 transition-all duration-150 hover:bg-blue-700'>Изменить</button>
                  <button onClick={() => handleDelete(n)}
                    className='p-2 rounded shadow-md bg-red-600 text-white  m-2 transition-all duration-150 hover:bg-red-700'>Удалить</button>
                </div>

              </div>
            ))) :
            (
              <form onSubmit={handleSubmit} className='flex flex-col w-full h-full p-6 shadow-md'>

                <textarea className="shadow-md rounded text-gray-700 p-4 mb-2 leading-relaxed" name="text" placeholder='Введите текст истории' onChange={(e) => { setText(e.target.value) }} />
                <button type='submit'
                  className='p-2 rounded shadow-md bg-blue-600 text-white m-2 transition-all duration-150 hover:bg-blue-700'>Сохранить</button>
              </form>
            )
          }


        </div>

        {histories.length ? (
          <form onSubmit={handleSubmit} className=' m-12 w-1/5 flex bg-white rounded-lg flex-col p-6 shadow-md'>
            <textarea className="text-gray-700 p-12 m-2 leading-relaxed" name="award_text" placeholder='Введите текст новости' onChange={(e) => { setText(e.target.value) }} />
            <button type='submit'
              className='p-2 rounded shadow-md bg-blue-600 text-white m-2 transition-all duration-150 hover:bg-blue-700'>Сохранить</button>
          </form>) : (<div></div>)
        }
      </div>


    </>

  )
}