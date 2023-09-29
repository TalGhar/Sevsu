import React, { useEffect, useState } from 'react'

type Props = {}

export default function HomePageCarousel({ }: Props) {

    const [currentImage, setCurrentImage] = useState(0);

    useEffect(() => {
        const interval = setInterval(() => {
            setCurrentImage((currentImage + 1) % 3);
        }, 3000);
        return () => clearInterval(interval);
    }, [currentImage]);



    return (
        <>
            <div className='flex opacity-40'>
                <div
                    style={{ backgroundImage: 'url(/storage/images/yacht1.jpg)' }}

                    className={`absolute h-full w-full transition-opacity bg-center bg-fixed duration-1000 ${currentImage === 0 ? 'opacity-100 z-1' : 'opacity-0 z--1'
                        }`}
                />
                <div
                    style={{ backgroundImage: 'url(/storage/images/yacht2.jpg)' }}
                    className={`absolute h-full w-full transition-opacity bg-center bg-fixed duration-1000 ${currentImage === 1 ? 'opacity-100 z-1' : 'opacity-0 z--1'
                        }`}
                />
                <div
                    style={{ backgroundImage: 'url(/storage/images/yacht3.jpg)' }}
                    className={`absolute h-full w-full transition-opacity bg-center bg-fixed duration-1000 ${currentImage === 2 ? 'opacity-100 z-1' : 'opacity-0 z--1'
                        }`}
                />

            </div>

            <div className='flex h-full text-white shadow-slate-800 text-center text-3xl shadow-lg p-12 '>
                Lorem ipsum dolor sit amet consectetur adipisicing elit. Itaque eligendi molestias laudantium. Quis minima praesentium commodi vitae, assumenda accusantium harum culpa excepturi ad voluptate similique a, minus itaque quam quos?
            </div>
        </>
    )
}
