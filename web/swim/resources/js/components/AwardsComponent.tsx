import axios from 'axios';
import React, { Children } from 'react'

type Props = {}

export default function AwardsComponent({ }: Props) {

    return (
        <section className="py-20">
            <div className="container mx-auto">
                <h2 className="text-4xl font-bold mb-8">Наши награды</h2>
                <div className="flex flex-wrap -mx-4">

                    <div className="w-full md:w-1/2 lg:w-1/3 px-4 mb-8">
                        <div className="bg-white rounded-lg shadow p-6">
                            <img src="/storage/images/bestSeller.png" alt="test" className='w-full h-full' />
                            <h3 className="text-xl font-bold mb-2">Награда за лучшего продавца</h3>
                            <p className="text-gray-700 leading-relaxed">
                                Награждается наша компания за продажу наибольшего количества морских судов в прошлом году.
                            </p>
                            
                        </div>
                        
                    </div>

                    {/* <div className="w-full md:w-1/2 lg:w-1/3 px-4 mb-8">
                        <div className="bg-white rounded-lg shadow p-6">
                            <img src="/storage/images/bestRent.jpg" alt="test" className='w-full h-full' />

                            <h3 className="text-xl font-bold mb-2">Награда лучшему арендатору</h3>
                            <p className="text-gray-700 leading-relaxed">
                                Награждается наша компания за сдачу в аренду в прошлом году наибольшего количества морских судов.
                            </p>
                        </div>
                    </div>

                    <div className="w-full md:w-1/2 lg:w-1/3 px-4 mb-8">
                        <div className="bg-white rounded-lg shadow p-6">
                            <img src="/storage/images/bestProductivity.jpg" alt="test" className='w-full h-full' />
                            <h3 className="text-xl font-bold mb-2">Награда за лучшую общую производительность</h3>
                            <p className="text-gray-700 leading-relaxed">
                                Награждается наша компания за достижение лучших общих показателей по продаже и аренде морских судов в прошлом году.
                            </p>
                        </div>
                    </div> */}

                </div>
            </div>
        </section>
    )
}