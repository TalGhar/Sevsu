import React from 'react'

type Props = {}

export default function HomePageNews({ }: Props) {
    return (

        <div className="w-1/3 h-1/3 p-6 ">
            <div className="bg-gradient-to-b to-emerald-100 from-orange-50 rounded-lg overflow-hidden shadow-lg">
                <img src="" alt="NewsImage" className="w-full h-48" />

                <div className="p-4 m-6 opacity-40 hover:opacity-100 bg-white rounded-lg shadow-md transition duration-500 ease-in-out transform hover:transition-transform hover:-translate-y-1">
                    <h3 className="text-lg font-bold mb-2 ">Title</h3>
                    <hr
                        className="my-4 h-0.5 border-t-0 bg-gray-300" />
                    <p className="p-5 rounded-lg ">Lorem ipsum, dolor sit amet consectetur adipisicing elit. Animi aliquid quisquam reprehenderit neque modi et porro eaque voluptatum, pariatur unde repudiandae facilis? Corrupti libero architecto dolores cumque neque consequatur fugiat?</p>
                </div>
            </div>
        </div>

    )
}