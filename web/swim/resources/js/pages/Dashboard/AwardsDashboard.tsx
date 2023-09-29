import { button } from '@material-tailwind/react';
import axios from 'axios';
import React, { useEffect, useRef, useState } from 'react'
import AwardsComponent from '../../components/AwardsComponent';

type Props = {}

export default function AwardsDashboard({ }: Props) {

  const [awards, setAwards] = useState([]);

  useEffect(() => {
    axios.get('/api/receive').then((response) => {
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

      })
      .catch(error => {
        console.error(error);

      })
  };

  const handleDelete = (id) => {
    // Navigate to the edit page for the Award with the given id
    console.log(`Deleting Award with id ${id}`);
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

  return (
    <>
      <div className='w-1/4 m-4 flex flex-row'>
        {awards.map((award) => (
          <div key={award.id} className='flex flex-col bg-white rounded-lg shadow p-6 mx-5'>
            <img src={'/award_images/'+award.award_image} alt={award.award_title} className='w-full h-full' onClick={() => handleImageClick(award)} />

            <input type='text' className='text-xl font-bold mb-2' value={award.award_title} onChange={(event) => handleTitleChange(award.id, event)} />
            <textarea className="text-gray-700 leading-relaxed" value={award.award_text} onChange={(event) => handleTextChange(award.id, event)} />
            <div className='flex flex-row justify-between'>
              <button onClick={() => handleEdit(award)}
                className='p-2 rounded shadow-md bg-blue-600 text-white m-2 transition-all duration-150 hover:bg-blue-700'>Изменить</button>
              <button onClick={() => handleDelete(award.id)}
                className='p-2 rounded shadow-md bg-red-600 text-white  m-2 transition-all duration-150 hover:bg-red-700'>Удалить</button>
            </div>
          </div>
        ))}
      </div>

    </>
  )
}