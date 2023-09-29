import { button } from '@material-tailwind/react';
import axios from 'axios';
import React, { useEffect, useRef, useState } from 'react'
import AwardsComponent from '../../components/AwardsComponent';
import { error } from 'console';

type Props = {}

export default function AwardsDashboard({ }: Props) {

  const [awards, setAwards] = useState([]);

  const [title, setTitle] = useState('');
  const [text, setText] = useState('');
  const [image, setImage] = useState<File | null>();

  const [errors, setErrors] = useState([]);


  useEffect(() => {
    axios.get('/api/awards-receive').then((response) => {
      setAwards(response.data)
    })
  }, []);

  const handleEdit = (award) => {
    const formData = new FormData();
    formData.append('id', award.id);
    formData.append('title', award.award_title);
    formData.append('text', award.award_text);
    formData.append('image', award.award_image);

    axios.post('/api/awards-edit', formData)
      .then(responce => {
        if (responce.data.success) {
          axios.get('/api/awards-receive').then((response) => {
            setAwards(response.data)
          })
        }
      })
  };

  const handleDelete = async (award) => {
    await axios.post('/api/awards-delete', award);
    axios.get('/api/awards-receive').then((response) => {
      setAwards(response.data)
    })
  };

  const handleImageClick = (award) => {
    const fileInput = document.createElement('input');
    fileInput.type = 'file';
    fileInput.accept = 'image/*';
    fileInput.addEventListener('change', (event) => {
      const fileObj = event.target.files && event.target.files[0];
      if (!fileObj) {
        return;
      }
      award.award_image = fileObj;
    });
    fileInput.click();
  };


  const handleTitleChange = (id, event) => {
    const newAwards = awards.map((award) => {
      if (award.id === id) {
        return { ...award, award_title: event.target.value };
      } else {
        return award;
      }
    });
    setAwards(newAwards);
  };

  const handleTextChange = (id, event) => {
    const newAwards = awards.map((award) => {
      if (award.id === id) {
        return { ...award, award_text: event.target.value };
      } else {
        return award;
      }
    });
    setAwards(newAwards);
  };

  const handleSubmit = async (event: React.FormEvent<HTMLFormElement>) => {
    event.preventDefault();
    const formData = new FormData();
    formData.append('award_title', title);
    formData.append('award_text', text);
    formData.append('award_image', image);
    const config = {
      headers: {
        'content-type': 'multipart/form-data',
      },
    }
    try {
      const response = await axios.post('/api/awards-store', formData, config);
      if (response.data.success) {
        axios.get('/api/awards-receive').then((response) => {
          setAwards(response.data);
        })
      }
    } catch (error) {
      console.log(error.response.data.errors);
    }

  }

  return (
    <>
      <div className='m-4 flex-wrap flex justify-center'>
        {awards.length ?
          (awards.map((award) => (

            <div key={award.id} className='w-1/5 flex m-5 flex-col bg-white rounded-lg shadow p-6'>
              <img src={'/award_images/' + award.award_image} alt={award.award_title} className='cursor-pointer w-full h-full' onClick={() => handleImageClick(award)} />

              <input type='text' className='text-xl font-bold mb-2' value={award.award_title} onChange={(event) => handleTitleChange(award.id, event)} />
              <textarea className="text-gray-700 leading-relaxed" value={award.award_text} onChange={(event) => handleTextChange(award.id, event)} />
              <div className='flex flex-row justify-between'>
                <button onClick={() => handleEdit(award)}
                  className='p-2 rounded shadow-md bg-blue-600 text-white m-2 transition-all duration-150 hover:bg-blue-700'>Изменить</button>
                <button onClick={() => handleDelete(award)}
                  className='p-2 rounded shadow-md bg-red-600 text-white  m-2 transition-all duration-150 hover:bg-red-700'>Удалить</button>
              </div>

            </div>
          ))) :
          (
            <form onSubmit={handleSubmit} className='flex flex-col w-full h-full p-6 shadow-md'>

              <input type="file" className="m-5 shadow-sm p-2" accept='image/*' name="award_image" id="image" onChange={(e) => { setImage(e.target.files[0]) }} />
              <input type='text' name="award_title" className='text-xl rounded font-bold mb-2 shadow-md p-4' placeholder='Введите заголовок награды' onChange={(e) => { setTitle(e.target.value) }} />
              <textarea className="shadow-md rounded text-gray-700 p-4 mb-2 leading-relaxed" name="award_text" placeholder='Введите текст награды' onChange={(e) => { setText(e.target.value) }} />
              <button type='submit'
                className='p-2 rounded shadow-md bg-blue-600 text-white m-2 transition-all duration-150 hover:bg-blue-700'>Сохранить</button>
            </form>
          )
        }


      </div>

      {awards.length ? (
        <form onSubmit={handleSubmit} className='w-1/5 flex flex-col p-6 shadow-md'>
          <input type="file" className="m-5 shadow-sm p-2" accept='image/*' name="award_image" id="image" onChange={(e) => { setImage(e.target.files[0]) }} />
          <input type='text' name="award_title" className='text-xl font-bold mb-2 shadow-md p-3' placeholder='Введите заголовок награды' onChange={(e) => { setTitle(e.target.value) }} />
          <textarea className="text-gray-700 p-12 m-2 leading-relaxed" name="award_text" placeholder='Введите текст награды' onChange={(e) => { setText(e.target.value) }} />
          <button type='submit'
            className='p-2 rounded shadow-md bg-blue-600 text-white m-2 transition-all duration-150 hover:bg-blue-700'>Сохранить</button>
        </form>) : (<div></div>)
      }

    </>
  )
}