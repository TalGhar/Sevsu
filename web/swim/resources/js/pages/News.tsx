import axios from 'axios';
import React, { useEffect, useState } from 'react'

type Props = {}

export default function News({ }: Props) {

  const [news, setNews] = useState([]);

  useEffect(() => {
    axios.get('/api/news-receive').then((response) => {
      setNews(response.data)
    })
  }, [])

  return (
    <section className="py-16 px-8 flex flex-wrap">
      <h2 className="text-3xl font-bold mb-8">Новости</h2>
      <div className='flex flex-wrap'>
        {news.map((n) => (
          <div key={n.id} className="w-1/3 h-1/3 p-6 ">
            <div className="bg-gradient-to-b to-emerald-100 from-orange-50 rounded-lg overflow-hidden shadow-lg">
              <img src={'/news_images/' + n.news_image} alt="NewsImage" className="w-full h-full" />

              <div className="p-4 m-6 opacity-40 hover:opacity-100 bg-white rounded-lg shadow-md transition duration-500 ease-in-out transform hover:transition-transform hover:-translate-y-1">
                <h3 className="text-lg font-bold mb-2 ">{n.news_title}</h3>
                <hr
                  className="my-4 h-0.5 border-t-0 bg-gray-300" />
                <p className="p-5 rounded-lg ">{n.news_text}</p>
              </div>
            </div>
          </div>
        ))}
      </div>
    </section>
  )
}