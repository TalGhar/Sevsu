import React from 'react'

type Props = {}


const reviews = [
  {
    name: 'John Doe',
    comment: 'Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed euismod, sapien vel bibendum bibendum, velit sapien bibendum sapien, vel bibendum sapien sapien vel bibendum bibendum.',
  },
  {
    name: 'Jane Smith',
    comment: 'Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed euismod, sapien vel bibendum bibendum, velit sapien bibendum sapien, vel bibendum sapien sapien vel bibendum bibendum.',
  },
  {
    name: 'Bob Johnson',
    comment: 'Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed euismod, sapien vel bibendum bibendum, velit sapien bibendum sapien, vel bibendum sapien sapien vel bibendum bibendum.',
  },
];

const Review = ({ name, comment }) => {
  return (
    <div className="bg-white p-4 rounded shadow">
      <h3 className="text-lg font-medium">{name}</h3>
      <p className="text-gray-600">{comment}</p>
    </div>
  );
};

export default function ReviewsComponent({ }: Props) {
  return (

    <section className="py-12">
      <div className="max-w-4xl mx-auto">
        <h2 className="text-3xl font-bold mb-8">Отзывы пользователей</h2>
        <div className="space-y-8">
          {reviews.map((review, index) => (
            <Review key={index} name={review.name} comment={review.comment} />
          ))}
        </div>
      </div>
    </section>
  )
}