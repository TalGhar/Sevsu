import { Button, Card, CardBody, CardFooter, CardHeader, Carousel, IconButton, Typography } from '@material-tailwind/react'
import React, { useState } from 'react'
import { ChevronLeftIcon, ChevronRightIcon } from "@heroicons/react/24/solid"

type Props = {}

export default function BoatComponent({ }: Props) {

    const [currentImage, setCurrentImage] = useState(0);
    const images = [
        '',
        '',
        ''
    ];

    const nextImage = () => {
        setCurrentImage(currentImage === images.length - 1 ? 0 : currentImage + 1);
    };

    const prevImage = () => {
        setCurrentImage(currentImage === 0 ? images.length - 1 : currentImage - 1);
    };

    return (
        <>
            <Card className='w-1/3 h-1/3 p-6'>
                <CardHeader className='shadow-md p-12 m-2'>
                    <div className="relative">
                        <img src={images[currentImage]} alt={`Image ${currentImage + 1}`} />
                        <div className="absolute top-1/2 left-0 transform -translate-y-1/2">
                            <button onClick={prevImage} className="bg-gray-800 text-white rounded-full p-2">
                                <ChevronLeftIcon className="h-6 w-6" />
                            </button>
                        </div>
                        <div className="absolute top-1/2 right-0 transform -translate-y-1/2">
                            <button onClick={nextImage} className="bg-gray-800 text-white rounded-full p-2">
                                <ChevronRightIcon className="h-6 w-6" />
                            </button>
                        </div>
                    </div>
                </CardHeader>
                <CardBody className='m-5 shadow-sm p-10'>
                    Description
                </CardBody>
                <CardFooter className='m-4'>
                    <Button>Купить</Button>
                </CardFooter>
            </Card>
        </>
    )
}