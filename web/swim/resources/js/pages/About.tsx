import React, { useEffect, useRef, useState } from 'react'
import axios from 'axios';
import { useLocation } from 'react-router-dom';
import ServicesComponent from '../components/ServicesComponent';

type Props = {}

export default function About({ }: Props) {

  const historyRef = useRef(null);
  const servicesRef = useRef(null);
  const awardsRef = useRef(null);
  const location = useLocation();

  const [histories, setHistories] = useState([]);
  const [awards, setAwards] = useState([]);

  useEffect(() => {
    if (location.hash === '#history') {
      historyRef.current.scrollIntoView({ behavior: 'smooth' });
    } else if (location.hash === '#services') {
      servicesRef.current.scrollIntoView({ behavior: 'smooth' });
    } else if (location.hash === '#awards') {
      awardsRef.current.scrollIntoView({ behavior: 'smooth' });
    } else if (location.hash === '#reviews') {
      reviewsRef.current.scrollIntoView({ behavior: 'smooth' });
    }
  }, [location.hash]);

  useEffect(() => {
    axios.get('/api/history-receive').then((response) => {
      setHistories(response.data)
    })
    axios.get('/api/awards-receive').then((response) => {
      setAwards(response.data)
    })
  }, []);

  return (
    <>
      <div className='bg-gradient-b from-slate-400 to-emerald-200'>

        <div ref={historyRef}>

          <div className="container mx-auto py-8 px-4">
            <h2 className="text-3xl font-bold mb-8">История</h2>
            <div className="flex flex-col md:flex-row md:space-x-8 ">

              <div className='m-4 flex-wrap flex justify-center'>
                {
                  (histories.map((n) => (

                    <div key={n.id} className=''>
                      <p className="mb-4 bg-gradient-to-b from-orange-50 from-30% to-emerald-100 rounded-md p-4 shadow-md">{n.history_text}</p>
                    </div>
                  )))
                }
              </div>

            </div>
          </div>

        </div>

        <div ref={servicesRef}>
          <ServicesComponent />
        </div>

        <div ref={awardsRef}>
          <section className="py-20">
            <div className="container mx-auto">
              <h2 className="text-4xl font-bold mb-8">Наши награды</h2>
              <div className="flex flex-wrap -mx-4">
                {
                  (awards.map((award) => (

                    <div key={award.id} className='w-1/5 flex m-5 flex-col bg-white rounded-lg shadow p-6'>

                      <h3 className="text-gray-700 leading-relaxed" ></h3>
                      <img src={'/award_images/' + award.award_image} className='w-full h-full' />
                      <h3 className="text-xl font-bold mb-2">{award.award_title}</h3>
                      <p className="text-gray-700 leading-relaxed">{award.award_text}</p>

                    </div>
                  )))
                }
              </div>
            </div>
          </section>

        </div>
      </div>

    </>
  )
}