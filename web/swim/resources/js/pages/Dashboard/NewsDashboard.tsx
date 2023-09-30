import axios from 'axios';
import React, { useEffect, useState } from 'react'

type Props = {}

export default function NewsDashboard({ }: Props) {

  const [news, setNews] = useState([]);

  const [title, setTitle] = useState('');
  const [text, setText] = useState('');
  const [image, setImage] = useState<File | null>();

  const [errors, setErrors] = useState([]);


  useEffect(() => {
    axios.get('/api/news-receive').then((response) => {
      setNews(response.data)
    })
  }, []);

  const handleEdit = (news) => {
    const formData = new FormData();
    formData.append('id', news.id);
    formData.append('title', news.news_title);
    formData.append('text', news.news_text);
    formData.append('image', news.news_image);

    axios.post('/api/news-edit', formData)
      .then(responce => {
        if (responce.data.success) {
          axios.get('/api/news-receive').then((response) => {
            setNews(response.data)
          })
        }
      })
  };

  const handleDelete = async (news) => {
    await axios.post('/api/news-delete', news);
    axios.get('/api/news-receive').then((response) => {
      setNews(response.data)
    })
  };

  const handleImageClick = (news) => {
    const fileInput = document.createElement('input');
    fileInput.type = 'file';
    fileInput.accept = 'image/*';
    fileInput.addEventListener('change', (event) => {
      const fileObj = event.target.files && event.target.files[0];
      if (!fileObj) {
        return;
      }
      news.news_image = fileObj;
    });
    fileInput.click();
  };


  const handleTitleChange = (id, event) => {
    const newNews = news.map((n) => {
      if (n.id === id) {
        return { ...n, news_title: event.target.value };
      } else {
        return n;
      }
    });
    setNews(newNews);
  };

  const handleTextChange = (id, event) => {
    const newNews = news.map((n) => {
      if (n.id === id) {
        return { ...n, news_text: event.target.value };
      } else {
        return n;
      }
    });
    setNews(newNews);
  };

  const handleSubmit = async (event: React.FormEvent<HTMLFormElement>) => {
    event.preventDefault();
    const formData = new FormData();
    formData.append('news_title', title);
    formData.append('news_text', text);
    formData.append('news_image', image);
    const config = {
      headers: {
        'content-type': 'multipart/form-data',
      },
    }
    try {
      const response = await axios.post('/api/news-store', formData, config);
      if (response.data.success) {
        axios.get('/api/news-receive').then((response) => {
          setNews(response.data);
        })
      }
    } catch (error) {
      console.log(error.response.data.errors);
    }

  }

  return (
    <>
      <div className='m-4 flex-wrap flex justify-center'>
        {news.length ?
          (news.map((n) => (

            <div key={n.id} className='w-1/5 flex m-5 flex-col bg-white rounded-lg shadow p-6'>
              <img src={'/news_images/' + n.news_image} alt={n.news_title} className='cursor-pointer w-full h-full' onClick={() => handleImageClick(n)} />

              <input type='text' className='text-xl font-bold mb-2' value={n.news_title} onChange={(event) => handleTitleChange(n.id, event)} />
              <textarea className="text-gray-700 leading-relaxed" value={n.news_text} onChange={(event) => handleTextChange(n.id, event)} />
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

              <input type="file" className="m-5 shadow-sm p-2" accept='image/*' name="news_image" id="image" onChange={(e) => { setImage(e.target.files[0]) }} />
              <input type='text' name="news_title" className='text-xl rounded font-bold mb-2 shadow-md p-4' placeholder='Введите заголовок новости' onChange={(e) => { setTitle(e.target.value) }} />
              <textarea className="shadow-md rounded text-gray-700 p-4 mb-2 leading-relaxed" name="news_text" placeholder='Введите текст новости' onChange={(e) => { setText(e.target.value) }} />
              <button type='submit'
                className='p-2 rounded shadow-md bg-blue-600 text-white m-2 transition-all duration-150 hover:bg-blue-700'>Сохранить</button>
            </form>
          )
        }


      </div>

      {news.length ? (
        <form onSubmit={handleSubmit} className='m-12 bg-white rounded-lg w-1/5 flex flex-col p-6 shadow-md'>
          <input type="file" className="m-5 shadow-sm p-2" accept='image/*' name="news_image" onChange={(e) => { setImage(e.target.files[0]) }} />
          <input type='text' name="news_title" className='text-xl font-bold mb-2 shadow-md p-3' placeholder='Введите заголовок новости' onChange={(e) => { setTitle(e.target.value) }} />
          <textarea className="text-gray-700 p-12 m-2 leading-relaxed" name="news_text" placeholder='Введите текст новости' onChange={(e) => { setText(e.target.value) }} />
          <button type='submit'
            className='p-2 rounded shadow-md bg-blue-600 text-white m-2 transition-all duration-150 hover:bg-blue-700'>Сохранить</button>
        </form>) : (<div></div>)
      }

    </>
  )
}