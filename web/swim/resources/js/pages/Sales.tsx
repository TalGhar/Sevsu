import { Carousel } from 'flowbite-react';
import axios from 'axios';
import React, { useEffect, useState } from 'react'

type Props = {}

export default function Sales({ }: Props) {

  const [boats, setBoats] = useState([]);
  const $client = localStorage.getItem('userId');

  useEffect(() => {
    axios.get('/api/boats-receive').then((response) => {
      setBoats(response.data);
      console.log($client);
    })
  }, [])

  const handleBuy = (boat) => {
    alert('Поздравляем с покупкой ' + boat.name)
    boat.owner_id = $client;
    axios.post('/api/boats-sell', boat)

      .then(response => {
        axios.get('/api/boats-receive').then((response) => {
          setBoats(response.data);
          console.log($client);
        })
      })
  }

  const handleRent = (boat) => {
    boat.rented_id = $client;
    const currentDate = new Date();
    const expireDate = new Date();
    expireDate.setDate(currentDate.getDate() + 7);
    console.log(currentDate)
    boat.status='rented';
    boat.rented_from=currentDate.toISOString().slice(0, 19).replace('T', ' ');
    boat.rented_to=expireDate.toISOString().slice(0, 19).replace('T', ' ');
    axios.post('/api/boats-rent', boat);
    alert('Вы успешно арендовали ' + boat.name + ' на неделю.')
  }

  return (
    <>
      <div className='flex flex-row flex-wrap'>
        {boats.map((boat) => (
          <div key={boat.id} className='w-1/4 shadow-lg bg-gradient-to-b from-slate-200 to-emerald-200 m-5 rounded'>
            <div className='w-full h-64 '>
              <Carousel >
                {boat.images.map((image) => (
                  <img key={image.id} src={'boat_images/' + image.filename} alt={image} className=" h-full w-full object-cover p-10" />
                ))}
              </Carousel>
            </div>

            <div className="p-4">
              <h2 className="text-2xl mb-3 shadow-sm p-2">{boat.name}</h2>
              <p className="text-base mb-3 p-6 text-slate-800 shadow-sm bg-gradient-to-br from-slate-100 to-emerald-300 ">{boat.description}</p>
              <p className="text-lg font-bold">{boat.price}</p>
              <div className="text-lg font-bold">
                {boat.status === 'created' || boat.status === 'sold' ? <div>Текущий владелец: {boat.owner_id.toString() === $client ? ' Вы' : boat.owner.name + ' ' + boat.owner.patron}</div> : <div>Арендовано до {boat.rented_to}</div>}
              </div>
              {boat.owner_id.toString() === $client || boat.status === 'rented' ? <></>: <div className='flex flex-row justify-between'>
                <div className='text-xl m-2 px-3 py-2 bg-gradient-to-tr from-orange-200 to-emerald-300 transition-colors duration-300 ease-in-out hover:from-emerald-300 hover:to-orange-200 rounded-lg' onClick={(e) => handleBuy(boat)}>Купить</div>
                <div className='text-xl m-2 px-3 py-2 bg-gradient-to-tr from-orange-200 to-emerald-300 transition-colors duration-300 ease-in-out hover:from-emerald-300 hover:to-orange-200 rounded-lg' onClick={(e) => handleRent(boat)}>Арендовать</div>
              </div>}
              
            </div>
          </div>
        ))}
      </div>

    </>
  )
}