import React, { useState } from 'react'
import BoatComponent from '../components/BoatComponent'
import { Carousel } from '@material-tailwind/react';
import { ChevronLeftIcon, ChevronRightIcon } from '@heroicons/react/24/solid';
import HomePageCarousel from '../components/HomePageCarousel';
import HomePageNews from '../components/HomePageNews';

type Props = {}


export default function Home({ }: Props) {

  return (
    <>
      {/* Header */}
      <section className="bg-gray-900">
        <div className=" relative justify-center h-96 w-full shadow-md">
          <HomePageCarousel />
        </div>
      </section>
      <div className='bg-gradient-to-b bg-scroll from-slate-200 from-30% to-emerald-200 to-95%'>

        {/* Lattest news */}
        <section className="py-16 px-8 flex flex-wrap">
          <h2 className="text-3xl font-bold mb-8">Последние новости</h2>
          <div className='flex flex-row'>
            <HomePageNews />
            <HomePageNews />
            <HomePageNews />
          </div>
        </section>
      </div>


    </>
  )
}