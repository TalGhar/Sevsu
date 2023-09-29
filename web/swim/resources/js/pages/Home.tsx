import React, { useEffect, useState } from 'react'
import HomePageCarousel from '../components/HomePageCarousel';
import axios from 'axios';

type Props = {}

export default function Home({ }: Props) {

  const [news, setNews] = useState([]);
  const [boats, setBoats] = useState([]);

  useEffect(() => {
    axios.get('/api/news-latest').then((response) => {
      setNews(response.data)
    });
  }, [])

  return (
    <>
      <div className='min-h-screen bg-gradient-to-b bg-scroll from-slate-200 from-30% to-emerald-200 to-95%'>

        <section className="bg-gray-900">
          <div className=" relative justify-center h-96 w-full shadow-md">
            <HomePageCarousel />
          </div>
        </section>

        <section className="py-16 px-8 flex flex-wrap">
          <h2 className="text-3xl font-bold mb-8">Последние новости</h2>
          <div className='flex flex-row'>
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

      </div>

    </>
  )
}