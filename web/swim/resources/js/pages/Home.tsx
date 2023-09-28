import React, { useState } from 'react'
import BoatComponent from '../components/BoatComponent'
import { Carousel } from '@material-tailwind/react';
import { ChevronLeftIcon, ChevronRightIcon } from '@heroicons/react/24/solid';
import HomePageCarousel from '../components/HomePageCarousel';

type Props = {}


export default function Home({ }: Props) {

  return (
    <>
      <section className="bg-gray-900">
        <div className=" relative justify-center h-96 w-full shadow-md">
          <HomePageCarousel />
        </div>
      </section>
      <div className='bg-gradient-to-b bg-scroll from-slate-200 from-5% to-emerald-100 to-95%'>
        <section className="py-16 ">
          <div className="container mx-auto px-4">
            <h2 className="text-3xl font-bold mb-8">Featured Boats & Yachts</h2>
            <div className="grid grid-cols-1 md:grid-cols-2 lg:grid-cols-3 gap-8">

              <div className="bg-white rounded-lg shadow-lg overflow-hidden">
                <img src="boat1.jpg" alt="Boat 1" className="w-full h-64 object-cover" />
                <div className="p-4">
                  <h3 className="text-xl font-bold mb-2">Boat 1</h3>
                  <p className="text-gray-600 mb-4">Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed euismod, diam vel tincidunt dignissim, velit sapien bibendum sapien, vel bibendum sapien sapien vel sapien.</p>
                  <a href="#" className="bg-blue-500 text-white py-2 px-6 rounded-full hover:bg-blue-600 transition duration-300">View Details</a>
                </div>
              </div>

              <div className="bg-white rounded-lg shadow-lg overflow-hidden">
                <img src="boat2.jpg" alt="Boat 2" className="w-full h-64 object-cover" />
                <div className="p-4">
                  <h3 className="text-xl font-bold mb-2">Boat 2</h3>
                  <p className="text-gray-600 mb-4">Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed euismod, diam vel tincidunt dignissim, velit sapien bibendum sapien, vel bibendum sapien sapien vel sapien.</p>
                  <a href="#" className="bg-blue-500 text-white py-2 px-6 rounded-full hover:bg-blue-600 transition duration-300">View Details</a>
                </div>
              </div>

              <div className="bg-white rounded-lg shadow-lg overflow-hidden">
                <img src="yacht1.jpg" alt="Yacht 1" className="w-full h-64 object-cover" />
                <div className="p-4">
                  <h3 className="text-xl font-bold mb-2">Yacht 1</h3>
                  <p className="text-gray-600 mb-4">Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed euismod, diam vel tincidunt dignissim, velit sapien bibendum sapien, vel bibendum sapien sapien vel sapien.</p>
                  <a href="#" className="bg-blue-500 text-white py-2 px-6 rounded-full hover:bg-blue-600 transition duration-300">View Details</a>
                </div>
              </div>

            </div>
          </div>
        </section>

        <section className=" py-20">
          <div className="container mx-auto px-4">
            <h2 className="text-3xl font-bold mb-8">Boat & Yacht Rentals</h2>
            <div className="grid grid-cols-1 md:grid-cols-2 lg:grid-cols-3 gap-8">
              <div className="bg-white rounded-lg shadow-lg overflow-hidden">
                <img src="rental1.jpg" alt="Rental 1" className="w-full h-64 object-cover" />
                <div className="p-4">
                  <h3 className="text-xl font-bold mb-2">Rental 1</h3>
                  <p className="text-gray-600 mb-4">Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed euismod, diam vel tincidunt dignissim, velit sapien bibendum sapien, vel bibendum sapien sapien vel sapien.</p>
                  <a href="#" className="bg-blue-500 text-white py-2 px-6 rounded-full hover:bg-blue-600 transition duration-300">View Details</a>
                </div>
              </div>
              <div className="bg-white rounded-lg shadow-lg overflow-hidden">
                <img src="rental2.jpg" alt="Rental 2" className="w-full h-64 object-cover" />
                <div className="p-4">
                  <h3 className="text-xl font-bold mb-2">Rental 2</h3>
                  <p className="text-gray-600 mb-4">Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed euismod, diam vel tincidunt dignissim, velit sapien bibendum sapien, vel bibendum sapien sapien vel sapien.</p>
                  <a href="#" className="bg-blue-500 text-white py-2 px-6 rounded-full hover:bg-blue-600 transition duration-300">View Details</a>
                </div>
              </div>
            </div>
          </div>
        </section>

      </div>


    </>
  )
}


{/* <div className="flex items-center justify-center">
            <ChevronLeftIcon className="w-1/5 flex left-0 cursor-pointer" onClick={prevSlide} />

            {images.map((image, index) => (
              <div
                key={index}
                className={`bg-red-200 transition-opacity duration-500 ${index === currentSlide ? 'opacity-100' : 'opacity-40'
                  }`}
              >
                <div>
                  <img src={image.src} alt={image.alt} className="" />
                  <div className="bg-gray-200 bg-opacity-50 text-black p-4">
                  </div>

                </div>

              </div>
            ))}
            <ChevronRightIcon className="w-1/5 flex right-0 cursor-pointer" onClick={nextSlide} />

          </div> */}